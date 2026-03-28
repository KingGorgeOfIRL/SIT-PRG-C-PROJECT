#include <stdio.h>
#include <string.h>
#include "db_func.h"
#include "../../assets/assets.h"

void cmd_help(char *args) {

    if (args && strlen(args) > 0) {
        printf("[!] Command [help] does not take in arguments.\n");
        return;
    }

    printf("\n\t----------------------------------------------\n");
    printf("\t%-15s %-30s\n", "Command", "Description");
    printf("\t----------------------------------------------\n");

    for (int i = 0; i < num_commands; i++) {
        printf("\t%-15s %-30s\n", commands[i].name, commands[i].description);
    }

    printf("\t----------------------------------------------\n");
}