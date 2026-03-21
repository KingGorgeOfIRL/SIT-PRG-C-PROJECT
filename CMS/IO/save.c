#include <stdio.h>
#include "../include/commands.h"

// use the same global variables defined in open.c
extern struct Student students[100];
extern int studentCount;

void saveStudents() {

    //Now it is using "w" to make changes instead of just reading the file with "r"
    FILE *pFile = fopen("DB/Sample_CMS.txt", "w");

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

    printf("CMS: Database successfully saved to file.\n");
}


//Testing purposes

// int main() {
//     printf("=== Testing save.c ===\n\n");

//     // Step 1: Load existing data from file
//     loadStudents();

//     printf("Loaded %d records from file.\n\n", studentCount);

//     // Step 2 (optional): Modify a record for testing
//     if (studentCount > 0) {
//         printf("Modifying first record for testing...\n");
//         students[0].mark += 5.0;  // add 5 points
//     }

//     // Step 3: Save data back to file
//     saveStudents();

//     // Step 4: Reload and show data to verify
//     studentCount = 0;  // clear array
//     loadStudents();
//     printf("\nAfter saving and reloading:\n");
//     showAll();

//     return 0;
// }

//command ran: gcc ./CMS/IO/open.c ./CMS/read/showall.c -o testing

