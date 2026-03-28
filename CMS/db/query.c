#include <stdio.h>
#include <string.h>
#include "db_func.h"
#include "../../assets/assets.h"
#include "../general/general_func.h"

void cmd_query(char *args) {
    int searchID;
    if (sscanf(args, "%d", &searchID) != 1) {
        printf("[!] Usage: query [ID]\n");
        return;
    }

    Student* result = query(searchID);

    if (result == NULL) {
        printf("Warning: No record found with Student ID %d.\n", searchID);
    } else {
        printf("\nRecord found:\n");
        printf("%-10s %-20s %-25s %-6s\n", "ID", "Name", "Programme", "Mark");
        printf("%-10s %-20s %-25s %-6s\n",
               "----------", "--------------------",
               "-------------------------", "------");
        printf("%-10d %-20s %-25s %-6.1f\n",
               result->id,
               result->name,
               result->programme,
               result->mark);
    }
}

// returns a pointer to the matching student record, or NULL if not found.
struct Student* query(int searchID) {
    int pos = binary_search(records, &recordCount, searchID);

    if (pos < recordCount && records[pos].node && records[pos].node->id == searchID) {
        return records[pos].node;
    }

    return NULL;
}