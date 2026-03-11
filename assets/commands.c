#include "commands.h"
#include "../func/database/help_func.h"
#include "../func/database/exit_func.h"

// Define the commands table
Command commands[] = {
    {"help", cmd_help, "Display help menu"},
    {"exit", cmd_exit, "Exit program"}
};

// Define the number of commands
int num_commands = sizeof(commands) / sizeof(commands[0]);