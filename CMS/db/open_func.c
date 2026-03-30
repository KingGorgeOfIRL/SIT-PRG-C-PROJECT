#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "db_func.h"
#include "../../assets/assets.h"
#include "../general/general_func.h"

void cmd_openStudents(char *args) {
    (void)args;
    char err_msg[255];
    records = openfile("StudentRecords/P1-7_CMS.txt", err_msg, &recordCount);
    recordCapacity = recordCount; // set initial capacity to count
    if (!records) {
        printf("[!] Failed to load students: %s\n", err_msg);
    } else {
        printf("[+] Successfully loaded %d student records.\n", recordCount);
    }
}

// open IO function to read from txt file
Record *openfile(const char *file_path, char err_msg[255], int *count){
    FILE *fptr = fopen(file_path,"r");
    int capacity = 1;
    *count = 0;

    /* invalid file*/
    Record *student_records = malloc(capacity * sizeof(Record));
    if (student_records == NULL) {
        strcpy(err_msg, "Initial memory allocation failure");
        if (fptr != NULL) {
            fclose(fptr);
        }
        return NULL;
    }else if (fptr == NULL) {
        strcpy(err_msg, "Failed to open file");
        free(student_records);
        return NULL;
    }

    int result;
    /* reads fileline for variables */
    int id = 0;
    char name[255] = "";
    char programme[255] = "";
    float mark = 0.0f;
    do{
        result = fscanf(fptr, "%d,%254[^,],%254[^,],%f", &id, name, programme, &mark);

        if (result == 4){
            int position = binary_search(student_records, count, id);
            result = insert(&student_records, count, capacity, position, id, name, programme, mark);
            if (result == -1){
                strcpy(err_msg, "Expanded memory allocation failure");
                fclose(fptr);
                free(student_records);
                return NULL;
            } else {
                capacity = result;
            }
        }else{
            int ch;
            while ((ch = fgetc(fptr)) != '\n' && ch != EOF) {
            }
        }
    }while (result != EOF);
    fclose(fptr);
    return student_records;
}
