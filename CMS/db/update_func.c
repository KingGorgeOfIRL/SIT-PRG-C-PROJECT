#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../assets/assets.h"
#include "db_func.h"
#include "../general/general_func.h"

void cmd_update(char *args) {
    int student_id;
    Student new_data;

    if (sscanf(args, "%d \"%63[^\"]\" \"%63[^\"]\" %f", &student_id, new_data.name, new_data.programme, &new_data.mark) != 4) {
        printf("[!] Usage: update [ID] \"Name\" \"Programme\" [Mark]\n");
        return;
    }

    int pos = binary_search(records, &recordCount, student_id);

    if (pos >= recordCount || records[pos].node->id != student_id) {
        printf("[!] Student ID not found\n");
        return;
    }

    int res = update_record(records, recordCount, pos, new_data.name, new_data.programme, new_data.mark);

    if (res == -1) {
        printf("[!] Update failed.\n");
        return;
    }

    printf("[+] Record updated successfully\n");
}

int update_record(Record *student_record, int count, int position, const char *name, const char *programme, float mark) {
    if (position < 0 || position >= count) {
        return -1; // invalid position
    }

    Student *student = student_record[position].node;

    strcpy(student->name, name);
    strcpy(student->programme, programme);
    student->mark = mark;

    return 0;
}