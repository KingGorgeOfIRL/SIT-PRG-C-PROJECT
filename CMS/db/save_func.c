#include <stdio.h>
#include <string.h>
#include "../../assets/assets.h"
#include "db_func.h"

// use the same global variables defined in open.c
extern struct Student students[100];
extern int studentCount;

void cmd_saveStudents(char *args) {
    (void)args;

    int res = save_records("StudentRecords/P1-7_CMS.txt", records, recordCount);

    if (res == -1) {
        printf("Error: Could not save to file.\n");
        return;
    }

    if (records == NULL || recordCount == 0) {
        printf("CMS: No records to save; file contains only header.\n");
        return;
    }

    printf("CMS: The database file 'P1-7_CMS.txt' is successfully saved.\n");
}

int save_records(const char *filename, Record *records, int recordCount) {
    FILE *pFile = fopen(filename, "w");
    if (pFile == NULL) {
        return -1; // file open failed
    }

    fprintf(pFile, "ID,Name,Programme,Mark\n");

    if (records != NULL && recordCount > 0) {
        for (int i = 0; i < recordCount; i++) {
            if (records[i].node == NULL) continue;

            fprintf(pFile, "%d,%s,%s,%.2f\n",
                    records[i].node->id,
                    records[i].node->name,
                    records[i].node->programme,
                    records[i].node->mark);
        }
    }

    fflush(pFile);
    fclose(pFile);

    return 0;
}