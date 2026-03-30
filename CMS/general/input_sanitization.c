#include "general_func.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define STUDENT_ID_LEN 7

int sanitize_input(char *buffer, size_t size, int to_lowercase) {

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
        printf("[-] Input exceeded limit (%lu)\n", (unsigned long)(size - 2));
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

    // lowercase only the main command token if needed
    if (to_lowercase) {
        char *p = buffer;
        while (*p && !isspace((unsigned char)*p)) {
            *p = (char)tolower((unsigned char)*p);
            p++;
        }
    }

    return 1; // success
}