#include <stdio.h>
#include <string.h>
#include "read.h"

// displays every record currently loaded in the database.
// returns the number of records, or 0 if none.
int showAll() {
    if (studentCount == 0) {
        printf("No records found.\n");
        return 0;
    }

    printf("\n%-10s %-20s %-25s %-6s\n", "ID", "Name", "Programme", "Mark");
    printf("%-10s %-20s %-25s %-6s\n",
           "----------", "--------------------",
           "-------------------------", "------");

    for (int i = 0; i < studentCount; i++) {
        printf("%-10d %-20s %-25s %-6.1f\n",
               students[i].id,
               students[i].name,
               students[i].programme,
               students[i].mark);
    }
    printf("\n");

    return studentCount;
}

// wrapper for the commands table (no arguments, no return value)
void cmd_showall() {
    showAll();
}