#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../../assets/assets.h"
#include "../general/general_func.h"
#include "db_func.h"

// returns student id if there is an error, assumes that student is in record
void cmd_delete(char *args) {
    int student_id;

    if (sscanf(args, "%d", &student_id) != 1) {
        printf("[!] Usage: delete [ID]\n");
        return;
    }

    int pos = binary_search(records, &recordCount, student_id);

    if (pos >= recordCount || records[pos].node == NULL || records[pos].node->id != student_id) {
        printf("[!] Student ID not found\n");
        return;
    }

    Student *student = records[pos].node;
    printf("\nRecord found:\n");
    printf("%-10s %-20s %-25s %-6s\n", "ID", "Name", "Programme", "Mark");
    printf("%-10d %-20s %-25s %-6.1f\n",
           student->id,
           student->name,
           student->programme,
           student->mark);
    printf("\nAre you sure you want to delete this record? [y/n]: ");

    char confirm[8];
    if (!fgets(confirm, sizeof(confirm), stdin)) {
        printf("[!] Deletion cancelled.\n");
        return;
    }

    confirm[0] = (char)tolower((unsigned char)confirm[0]);
    if (confirm[0] != 'y') {
        printf("[*] Deletion cancelled.\n");
        return;
    }

    int res = delete_record(records, &recordCount, pos);

    if (res == -1) {
        printf("[!] Deletion failed.\n");
        return;
    }

    printf("[+] Record deleted successfully\n");
}

int delete_record(Record *student_record, int *count, int position) {
    if (position < 0 || position >= *count) {
        return -1; // invalid position
    }

    // free the student node
    free(student_record[position].node);

    // shift elements left
    for (int i = position; i < *count - 1; i++) {
        student_record[i] = student_record[i + 1];
    }

    (*count)--;

    return 0; // success
}