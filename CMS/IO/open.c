#include <stdio.h>
#include <string.h>

//This allows "commands.h" header file to find "loadStudents()" function
#include "../include/commands.h"


struct Student students[100];
int studentCount = 0;

// a void function doesn't return anything, this function opens the file and stores
// the data from the file in a buffer
void loadStudents(){

    // opens the file and stores it in a pointer named pFile
    FILE *pFile = fopen("DB/Sample_CMS.txt", "r");

    //create a buffer to temporarily store data in memory
    char buffer[1024] = {0};

    //If file cannot be found, pointer returns a NULL
    if(pFile == NULL){

        //returns one, to the system, meaning an error has been found.
        printf("Could not open file\n");
        return;
    }

    // prints to the terminal and notifies the user that the database file has opened
    printf("CMS: The database file “Sample_CMS.txt” is successfully opened.\n");

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

//     // load data from file
//     loadStudents();

//     // display loaded data
//     int count = showAll();

//     printf("Total records loaded: %d\n", count);

//     return 0;
// }

//command ran: gcc ./CMS/IO/open.c ./CMS/IO/save.c ./CMS/read/showall.c -o testing

