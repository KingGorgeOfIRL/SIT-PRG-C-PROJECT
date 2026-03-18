#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "insert_func.h"
#include "../general/input_sanitization.h"
#include "read.h"

#define STUDENT_ID_LEN 7
#define FILE_NAME "./StudentRecords/P1-7_CMS.txt"

extern struct Student students[100];
extern int studentCount;

void cmd_insert(char *args) {
    char student_id_str[STUDENT_ID_LEN + 1];
    int student_id;
    #define NAME_LEN 64
    #define PROGRAMME_LEN 64

    if (sscanf(args, "%63s", student_id_str) != 1) {
        printf("[!] Usage: insert [student ID]\n");
        return;
    }

    if (strlen(student_id_str) != STUDENT_ID_LEN) {
        printf("[!] Student ID must be exactly 7 digits.\n");
        return;
    }

    for (int i = 0; i < STUDENT_ID_LEN; i++) {
        if (!isdigit(student_id_str[i])) {
            printf("[!] Student ID must contain only numbers.\n");
            return;
        }
    }

    student_id = atoi(student_id_str);

    // load db into list
    studentCount = 0;
    FILE *fp_read = fopen(FILE_NAME, "r");
    if (fp_read) {
        char line[256];
        while (fgets(line, sizeof(line), fp_read) && studentCount < 100) {
            int id;
            char name[100], programme[100];
            float mark;

            if (sscanf(line, "%d,%99[^,],%99[^,],%f", &id, name, programme, &mark) == 4) {
                students[studentCount].id = id;
                strcpy(students[studentCount].name, name);
                strcpy(students[studentCount].programme, programme);
                students[studentCount].mark = mark;
                studentCount++;
            }
        }
        fclose(fp_read);
    }

    // query() for duplication
    if (query(student_id) != NULL) {
        printf("[!] Error: Student ID already exists. Insertion cancelled.\n");
        return;
    }

    char name[NAME_LEN + 1];
    char programme[PROGRAMME_LEN + 1];
    char mark_input[6];
    float mark;

    printf("Enter Name (1-%d chars): ", NAME_LEN);
    if (!sanitize_input(name, sizeof(name), 0)) return;
    if (strlen(name) == 0 || strlen(name) > NAME_LEN) {
        printf("[!] Name must be 1-%d characters.\n", NAME_LEN);
        return;
    }

    printf("Enter Programme (1-%d chars): ", PROGRAMME_LEN);
    if (!sanitize_input(programme, sizeof(programme), 0)) return;
    if (strlen(programme) == 0 || strlen(programme) > PROGRAMME_LEN) {
        printf("[!] Programme must be 1-%d characters.\n", PROGRAMME_LEN);
        return;
    }

    printf("Enter Mark (0-100, max 5 chars): ");
    if (!sanitize_input(mark_input, sizeof(mark_input), 0)) return;

    if (strlen(mark_input) > 5) {
        printf("[!] Mark input too long. Must be 0-100.\n");
        return;
    }

    if (sscanf(mark_input, "%f", &mark) != 1 || mark < 0 || mark > 100) {
        printf("[!] Invalid mark. Must be 0-100.\n");
        return;
    }

    // append to file
    FILE *fp = fopen(FILE_NAME, "a");
    if (fp == NULL) {
        printf("[!] Error opening file.\n");
        return;
    }

    fprintf(fp, "%d,%s,%s,%.1f\n", student_id, name, programme, mark);
    fclose(fp);

    printf("[+] Record inserted successfully.\n");
}