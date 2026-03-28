#include <stdio.h>
#include "../../assets/assets.h"
#include "db_func.h"

void cmd_showall(char *args) {
    (void)args;
    showAll();
}

// displays every record currently loaded in the database.
// returns the number of records, or 0 if none.
int showAll() {
    if (recordCount == 0) {
        printf("No records found. (Have you [load] the database?)\n");
        return 0;
    }

    printf("\n%-10s %-20s %-25s %-6s\n", "ID", "Name", "Programme", "Mark");
    printf("%-10s %-20s %-25s %-6s\n",
           "----------", "--------------------",
           "-------------------------", "------");

    for (int i = 0; i < recordCount; i++) {
        Student *current = records[i].node;
        if (current == NULL) continue;

        printf("%-10d %-20s %-25s %-6.1f\n",
               current->id,
               current->name,
               current->programme,
               current->mark);
    }
    printf("\n");

    return recordCount;
}
