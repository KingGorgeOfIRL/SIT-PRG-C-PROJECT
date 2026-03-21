#include <stdio.h>
#include <string.h>
#include "db_func.h"
#include "../../assets/commands.h"

void cmd_help(char *args) {

    if (args && strlen(args) > 0) {
        printf("[!] Command [help] does not take in arguments.\n");
        return;
    }

    printf("\n\t------------------------------------\n");
    printf("\tCommand\t\tDescription\n");
    printf("\t------------------------------------\n");

    for (int i = 0; i < num_commands; i++) {
        if (strlen(commands[i].name) < 8)
            printf("\t%s\t\t%s\n", commands[i].name, commands[i].description);
        else
            printf("\t%s\t%s\n", commands[i].name, commands[i].description);
    }

    printf("\t------------------------------------\n");

}