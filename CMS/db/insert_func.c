#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "db_func.h"
#include "../../assets/assets.h"
#include "../general/general_func.h"

#define STUDENT_ID_LEN 7
#define NAME_LEN 64
#define PROGRAMME_LEN 64

void cmd_insert(char *args) {
    char student_id_str[STUDENT_ID_LEN + 1];
    int student_id;
    char name[NAME_LEN + 1];
    char programme[PROGRAMME_LEN + 1];
    float mark;

    if (sscanf(args, "%7s \"%63[^\"]\" \"%63[^\"]\" %f",
               student_id_str, name, programme, &mark) != 4) {
        printf("[!] Usage: insert [ID] \"Name\" \"Programme\" [Mark]\n");
        return;
    }

    // validate ID length
    if (strlen(student_id_str) != STUDENT_ID_LEN) {
        printf("[!] Student ID must be exactly 7 digits.\n");
        return;
    }

    // validate ID digits
    for (int i = 0; i < STUDENT_ID_LEN; i++) {
        if (!isdigit(student_id_str[i])) {
            printf("[!] Student ID must contain only numbers.\n");
            return;
        }
    }

    student_id = atoi(student_id_str);

    // validate mark
    if (mark < 0 || mark > 100) {
        printf("[!] Invalid mark. Must be 0-100.\n");
        return;
    }

    // check duplicate
    int pos = binary_search(records, &recordCount, student_id);
    if (pos < recordCount && records[pos].node->id == student_id) {
        printf("[!] Error: Student ID already exists. Insertion cancelled.\n");
        return;
    }

    int res = insert(&records, &recordCount, recordCapacity, pos, student_id, name, programme, mark);

    if (res == -1) {
        printf("[!] Memory allocation failed. Insertion cancelled.\n");
        return;
    } else {
        recordCapacity = res;
    }

    printf("[+] Record inserted successfully.\n");
}

// assumes that student is not in record
int insert(Record **student_record, int *count, int capacity, int position, int id, const char *name, const char *programme, float mark) {
    /* expanding memory allocation */
    if (*count == capacity) {
        capacity += 1;
        Record *temp = realloc(*student_record, capacity * sizeof(Record));
        if (temp == NULL) {
            return -1;
        }
        *student_record = temp;
    }

    /* shift elements to the right */
    for (int i = *count; i > position; i--) {
        (*student_record)[i] = (*student_record)[i-1];
    }

    /* create new student*/
    Student *new_student = malloc(sizeof(Student));
    if (new_student == NULL) {
        return -1;
    } else {
        new_student->mark = mark;
        new_student->id = id;
        strcpy(new_student->name, name);
        strcpy(new_student->programme, programme);
    }

    (*student_record)[position].node = new_student;
    (*count)++;
    return capacity;
}