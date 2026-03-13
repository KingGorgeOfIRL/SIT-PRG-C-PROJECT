#include <stdio.h>
#include <string.h>
#include "../include/commands.h"

// -------------------------------------------------------
// SHOW ALL
// Displays every record currently loaded in the database.
// -------------------------------------------------------
void showAll() {
    if (studentCount == 0) {
        printf("No records found.\n");
        return;
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
}

// -------------------------------------------------------
// QUERY
// Searches for a record by student ID and displays it.
// -------------------------------------------------------
void query() {
    int searchID;

    printf("Enter Student ID to search: ");
    scanf("%d", &searchID);

    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == searchID) {
            printf("\nRecord found:\n");
            printf("%-10s %-20s %-25s %-6s\n", "ID", "Name", "Programme", "Mark");
            printf("%-10s %-20s %-25s %-6s\n",
                   "----------", "--------------------",
                   "-------------------------", "------");
            printf("%-10d %-20s %-25s %-6.1f\n",
                   students[i].id,
                   students[i].name,
                   students[i].programme,
                   students[i].mark);
            printf("\n");
            return;
        }
    }

    printf("Warning: No record found with Student ID %d.\n\n", searchID);
}
