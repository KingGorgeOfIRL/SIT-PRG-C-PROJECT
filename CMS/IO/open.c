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

    // skips the first 2 sentences
    fgets(buffer, sizeof(buffer), pFile);
    fgets(buffer, sizeof(buffer), pFile);

    //reads a line from the file, copies it into the buffer, and then returns the text stored in buffer
    //Only if pFile is NOT empty
    while(fgets(buffer, sizeof(buffer), pFile) != NULL){

        //sscanf is used since we are reading from a string (buffer) instead of a variable
        // %[^,] reads a string until the next comma, first one reads the name, second one reads the programme
        // %[^,] is used as the name and programme data have spaces
        sscanf(buffer,"%d,%[^,],%[^,],%f",

            &students[studentCount].id,
            students[studentCount].name,
            students[studentCount].programme,
            &students[studentCount].mark);

        //keeps track of how many students are there
        studentCount++;

    }

    fclose(pFile);


}


//For testing purposes
// int main() {

//     // Use loadStudents() to grab id, name, programme and marks
//     loadStudents();

//     for(int i = 0; i < studentCount; i++){
//         printf("ID: %d\n", students[i].id);
//         printf("Name: %s\n", students[i].name);
//         printf("Programme: %s\n", students[i].programme);
//         printf("Mark: %.1f\n\n", students[i].mark);
//     }

//     return 0;

// }