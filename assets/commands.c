#include "commands.h"
#include "../func/database/help_func.h"
#include "../func/database/exit_func.h"
#include "../func/database/insert_func.h"

// command table
Command commands[] = {
    {"help", cmd_help, "Display help menu"},
    {"exit", cmd_exit, "Exit program"},
    {"insert", cmd_insert, "Insert new entry"}
};

// number of commands
int num_commands = sizeof(commands) / sizeof(commands[0]);