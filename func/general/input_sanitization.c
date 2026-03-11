#include "input_sanitization.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int sanitize_input(char *buffer, size_t size) {

    // read input
    if (fgets(buffer, size, stdin) == NULL) {
        return 0; // failed to read
    }

    // check if newline exists
    char *newline = strchr(buffer, '\n');

    // input too long if no newline
    if (!newline) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF); // flush extra chars
        printf("[-] Input exceeded limit (%zu)\n", size - 2);
        return 0; // failed
    }

    *newline = '\0'; // replace newline with null terminator

    // remove whitespaces (  front)
    char *start = buffer;
    while(*start && isspace((unsigned char)*start)) {
        start++;
    }

    // remove whitespaces (back  )
    char *end = buffer + strlen(buffer)-1;
    while (end >= start && isspace((unsigned char)*end)) {
        *end = '\0';
        end--;
    }

    // shift trimmed string to start if needed
    if (start != buffer) {
        memmove(buffer, start, strlen(start) + 1); // +1 for null terminator
    }

    // lowercase everything
    for (size_t i = 0; buffer[i]; i++) {
        buffer[i] = (char)tolower((unsigned char)buffer[i]);
    }

    return 1; // success
}