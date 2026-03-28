#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "db_func.h"

void cmd_exit(char *args) {
    if (args && strlen(args) > 0) {
        printf("[!] Command [exit] does not take in arguments.\n");
        return;
    }
    printf("[*] Saving database...\n");
    cmd_saveStudents(""); // auto-save on exit
    printf("[*] Exiting...\n\n");
    exit(0);
}