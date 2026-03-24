#include <stdio.h>
#include <string.h>

//This allows "commands.h" header file to find the data structure for students
#include "../../assets/commands.h"
#include "io.h"

struct Student students[100];
int studentCount = 0;

// a void function doesn't return anything, this function opens the file and stores
// the data from the file in a buffer
void cmd_loadStudents(char *args){

    // opens the file and stores it in a pointer named pFile
    FILE *pFile = fopen("StudentRecords/P1-7_CMS.txt", "r");

    //create a buffer to temporarily store data in memory
    char buffer[1024] = {0};

    //If file cannot be found, pointer returns a NULL
    if(pFile == NULL){

        //returns one, to the system, meaning an error has been found.
        printf("Could not open file\n");
        return;
    }

    // prints to the terminal and notifies the user that the database file has opened
    printf("CMS: The database file “P1-7_CMS.txt” is successfully opened.\n");

    //reads a line from the file, copies it into the buffer, and then returns the text stored in buffer
    //Only if pFile is NOT empty
    while(fgets(buffer, sizeof(buffer), pFile) != NULL){

        int id;
        char name[255];
        char programme[255];
        float mark;

        //sscanf is used since we are reading from a string (buffer) instead of a variable
        // %254[^,] reads a string (of 254 characters) until the next comma, first one reads the name, second one reads the programme
        // %254[^,] is used as the name and programme data have spaces
        int result = sscanf(buffer, "%d,%254[^,],%254[^,],%f", &id, name, programme, &mark);

        //if result != 4 the it just ignores the line of data and goes to the next one
        if (result == 4) {
            students[studentCount].id = id;
            strcpy(students[studentCount].name, name);
            strcpy(students[studentCount].programme, programme);
            students[studentCount].mark = mark;

            // keeps track of how many students there are
            studentCount++;
        } 

    }

    fclose(pFile);


}

//Testing purposes

// int main() {
//     printf("=== Testing open.c ===\n\n");

//     // Step 1: Load data from file
//     cmd_loadStudents(NULL);

//     // Step 2: Display all loaded students
//     printf("\nLoaded %d student(s):\n", studentCount);
//     for (int i = 0; i < studentCount; i++) {
//         printf("ID: %d\n", students[i].id);
//         printf("Name: %s\n", students[i].name);
//         printf("Programme: %s\n", students[i].programme);
//         printf("Mark: %.2f\n", students[i].mark);
//         printf("-----------------------\n");
//     }

//     return 0;
// }

//command ran: gcc ./CMS/IO/open.c -o test_open

