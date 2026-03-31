#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "db_func.h"

void cmd_exit(char *args) {
    if (args && strlen(args) > 0) {
        printf("[!] Command [exit] does not take in arguments.\n");
        return;
    }

    printf("[*] Exiting...\n\n");
    exit(0);
}