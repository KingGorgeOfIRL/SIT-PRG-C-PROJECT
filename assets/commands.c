#include "commands.h"
#include "../func/database/help_func.h"
#include "../func/database/exit_func.h"
#include "../CMS/read/read.h"

// Define the commands table
Command commands[] = {
    {"help", cmd_help, "Display help menu"},
    {"exit", cmd_exit, "Exit program"},
    {"showall", cmd_showall, "Display all records"},
    {"query",   cmd_query,   "Search for a record"}
};

// Define the number of commands
int num_commands = sizeof(commands) / sizeof(commands[0]);