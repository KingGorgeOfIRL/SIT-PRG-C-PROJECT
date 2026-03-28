#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "assets/assets.h"
#include "CMS/db/db_func.h"
#include "CMS/general/general_func.h"

#define MAX_INPUT 10000

int main() {

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