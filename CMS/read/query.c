#include "read.h"

// 🔹 Define the actual globals (ONLY here)
struct Student students[100];
int studentCount = 0;

// 🔹 query function
struct Student* query(int searchID) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == searchID) {
            return &students[i];
        }
    }
    return 0;
}

// wrapper for the commands table
void cmd_query() {
    int searchID;
    printf("Enter Student ID to search: ");
    scanf("%d", &searchID);
 
    struct Student* result = query(searchID);
    if (result == 0) {
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