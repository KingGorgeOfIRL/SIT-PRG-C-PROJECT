#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "assets/commands.h"
#include "func/general/timestamp.h"
#include "func/general/input_sanitization.h"
#include "func/database/help_func.h"
#include "func/database/exit_func.h"

#define MAX_INPUT 10

int main() {

    char input[MAX_INPUT];
    char timestamp[32]; // size = 21 (incl. null term.)

    // infinite
    while (1) {

        get_timestamp(timestamp, sizeof(timestamp));
        printf("\n[%s] >> ", timestamp);

        if (!sanitize_input(input, sizeof(input))) {
            continue;
        }

        // lookup commands
        int found = 0;
        // loop through all command to see if there's any matches
        for (int i = 0; i < num_commands; i++) {
            if (strcmp(input, commands[i].name) == 0) {
                commands[i].func();
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