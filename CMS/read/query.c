#include <stdio.h>
#include <string.h>
#include "read.h"

// returns a pointer to the matching student record, or NULL if not found.
struct Student* query(int searchID) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == searchID) {
            return &students[i];
        }
    }
    return NULL;
}

// wrapper for the commands table
void cmd_query(char *args) {
    int searchID;
    printf("Enter Student ID to search: ");
    scanf("%d", &searchID);

    struct Student* result = query(searchID);
    if (result == NULL) {
        printf("Warning: No record found with Student ID %d.\n", searchID);
    } else {
        printf("\nRecord found:\n");
        printf("%-10s %-20s %-25s %-6s\n", "ID", "Name", "Programme", "Mark");
        printf("%-10s %-20s %-25s %-6s\n",
               "----------", "--------------------",
               "-------------------------", "------");
        printf("%-10d %-20s %-25s %-6.1f\n",
               result->id, result->name,
               result->programme, result->mark);
        printf("\n");
    }
}