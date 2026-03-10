#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>  

#include "include/commands.h"


int main() {


    char user_input[100];
    bool exit_flag = false;

    printf(
    "                                                                                                     \n"
    "                                              Declaration\n"
    "                                                                                                     \n"
    "\n"
    "Students are not allowed to copy assessment solutions from another person or other places, including\n"
    "AI platforms or tools. It is the students’ responsibility to guarantee that their solutions are their own\n"
    "work. Meanwhile, the students must also ensure that their work is not accessible by others. Where such\n"
    "plagiarism is detected, both of the assessments involved will receive ZERO mark.\n"
    "\n"
    "We hereby declare that:\n"
    "\n"
    "1. We fully understand and agree to the abovementioned policy.\n"
    "2. We did not copy any materials from others or from other places, e.g., AI platforms or tools.\n"
    "3. We did not share our materials with others or upload to any other places for public access.\n"
    "4. We agree that we will not disclose any information or material of the team project to others or\n"
    "   upload to any other places for public access\n"
    "5. We agree that our project will receive Zero mark if any misalignment with the abovementioned\n"
    "   policies is detected.\n"
    "\n"
    "Declared by: Group 7\n"
    "Team members:\n"
    "\n"
    "1. Asher Lee Bing Xuan\n"
    "2. Alden Chia Yu Xiang\n"
    "3. Lennon Poh Chin Hng\n"
    "4. Ray Tan JunTao\n"
    "\n"
    "Date: To be confirmed and decided by the rest of the team lol\n"
    );


    while (!exit_flag) {

        printf("C_Project_CMS:\n");
        fgets(user_input, sizeof(user_input), stdin);

        // remove newline (required if using fgets)
        user_input[strcspn(user_input, "\n")] = 0;

        // This converts all user input to uppercase
        for (int i = 0; user_input[i]; i++) {

            user_input[i] = toupper(user_input[i]);

        }

        if (strcmp(user_input, "OPEN") == 0) {

            loadStudents();

                // For testing purposes, to be used and deleted later on
                for(int i = 0; i < studentCount; i++){
                    printf("ID: %d\n", students[i].id);
                    printf("Name: %s\n", students[i].name);
                    printf("Programme: %s\n", students[i].programme);
                    printf("Mark: %.1f\n\n", students[i].mark);
                }

        } else if (strcmp(user_input, "SHOW ALL") == 0) {

            // some stuff

        } else if (strcmp(user_input, "INSERT") == 0) {

            // some stuff

        } else if (strcmp(user_input, "QUERY") == 0) {

            // some stuff

        } else if (strcmp(user_input, "UPDATE") == 0) {

            // some stuff

        } else if (strcmp(user_input, "DELETE") == 0) {

            // some stuff

        } else if (strcmp(user_input, "SAVE") == 0) {

            // some stuff

        } else if (strcmp(user_input, "EXIT") == 0) {

            exit_flag = true;

        } else {

            printf("Please type in a valid command.\n");

        }
    }

    return 0;
}