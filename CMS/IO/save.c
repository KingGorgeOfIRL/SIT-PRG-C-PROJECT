#include <stdio.h>
#include <string.h>


#include "../../assets/commands.h"
#include "io.h"

// use the same global variables defined in open.c
extern struct Student students[100];
extern int studentCount;

void cmd_saveStudents(char *args) {

    //Now it is using "w" to make changes instead of just reading the file with "r"
    FILE *pFile = fopen("StudentRecords/P1-7_CMS.txt", "w");

    if (pFile == NULL) {
        printf("Error: Could not save to file.\n");
        return;
    }

    // Write headers (This adds back the headers into the file when updating the whole file for readability)
    fprintf(pFile, "Student Database\n");
    fprintf(pFile, "ID,Name,Programme,Mark\n");

    // write all valid student records
    for (int i = 0; i < studentCount; i++) {

        // basic validation
        if (students[i].id <= 0) continue;

        fprintf(pFile, "%d,%s,%s,%.2f\n",
                students[i].id,
                students[i].name,
                students[i].programme,
                students[i].mark);
    }

    // ensure everything is written before closing
    fflush(pFile);
    fclose(pFile);

    printf("CMS: The database file 'P1-7_CMS.txt' is successfully saved.\n");
}


//testing
// int main() {
//     printf("=== Testing save.c ===\n\n");

//     // Create some dummy data
//     studentCount = 2;

//     students[0].id = 1;
//     strcpy(students[0].name, "Alice Tan");
//     strcpy(students[0].programme, "Computer Science");
//     students[0].mark = 85.5;

//     students[1].id = 2;
//     strcpy(students[1].name, "Bob Lim");
//     strcpy(students[1].programme, "Information Systems");
//     students[1].mark = 78.0;

//     // Call save function
//     cmd_saveStudents(NULL);

//     return 0;
// }
