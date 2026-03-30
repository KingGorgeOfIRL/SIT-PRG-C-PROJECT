#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "db_func.h"
#include "../../assets/assets.h"
#include "../general/general_func.h"

#define STUDENT_ID_LEN 7

void cmd_query(char *args) {
    char student_id_str[STUDENT_ID_LEN + 1];
    char extra[2] = {0};
    int searchID;

    if (sscanf(args, "%7s %1s", student_id_str, extra) != 1) {
        printf("[!] Usage: query [ID]\n");
        return;
    }

    if (strlen(student_id_str) != STUDENT_ID_LEN) {
        printf("[!] Student ID must be exactly 7 digits.\n");
        return;
    }

    for (int i = 0; i < STUDENT_ID_LEN; i++) {
        if (!isdigit((unsigned char)student_id_str[i])) {
            printf("[!] Student ID must contain only numbers.\n");
            return;
        }
    }

    searchID = atoi(student_id_str);

    Student* result = query(searchID);

    if (result == NULL) {
        printf("[x] No %d Student ID not found. (Have you [open] the database?)\n", searchID);
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