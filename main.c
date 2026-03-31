#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "assets/assets.h"
#include "CMS/db/db_func.h"
#include "CMS/general/general_func.h"

#define MAX_INPUT 10000

int main() {

    printf("\n\nDeclaration\n\n"
           "Students are not allowed to copy assessment solutions from another person or other places, including\n"
           "AI platforms or tools. It is the students' responsibility to guarantee that their solutions are their own\n"
           "work. Meanwhile, the students must also ensure that their work is not accessible by others. Where such\n"
           "plagiarism is detected, both of the assessments involved will receive ZERO mark.\n"
           "We hereby declare that:\n"
           "\t- We fully understand and agree to the abovementioned policy.\n"
           "\t- We did not copy any materials from others or from other places, e.g., AI platforms or tools.\n"
           "\t- We did not share our materials with others or upload to any other places for public access.\n"
           "\t- We agree that we will not disclose any information or material of the team project to others or\n"
           "\tupload to any other places for public access.\n"
           "\t- We agree that our project will receive Zero mark if any misalignment with the above mentioned\n"
           "\tpolicies is detected.\n\n"
           "Declared by: Group Name (please insert your group name)\n"
           "Team members:\n"
           "\t1. Asher Lee Bing Xuan\n"
           "\t2. Alden Chia Yu Xiang\n"
           "\t3. Lennon Poh Chin Hng\n"
           "\t4. Ray Tan JunTao\n"
           "Date: 31 March 2026\n\n"
    );

    char input[MAX_INPUT];
    char timestamp[32]; // size = 21 (incl. null term.)

    while (1) {

        get_timestamp(timestamp, sizeof(timestamp));
        printf("\n[%s] P1-7 >> ", timestamp);

        if (!sanitize_input(input, sizeof(input), 1)) {
            continue;
        };

        char *cmd = strtok(input, " ");
        char *args = strtok(NULL, "");

        if (!cmd) {continue;}
        if (!args) {args = "";}

        // lookup commands
        int found = 0;
        for (int i = 0; i < num_commands; i++) {
            // check for multi-word
            if (strchr(commands[i].name, ' ') != NULL) {
                char full_cmd[256];
                snprintf(full_cmd, sizeof(full_cmd), "%s %s", cmd, args ? args : "");
                
                if (strcmp(full_cmd, commands[i].name) == 0) {
                    commands[i].func(""); // multi-word commands get empty args
                    found = 1;
                    break;
                }
                
            } else if (strcmp(cmd, commands[i].name) == 0) {
                commands[i].func(args);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("[*] Command does not exist. Enter [help] for more information.\n");
        }
    }

    return 0;
}