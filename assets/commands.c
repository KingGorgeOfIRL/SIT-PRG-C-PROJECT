#include "commands.h"
#include "../func/database/help_func.h"
#include "../func/database/exit_func.h"
#include "../CMS/read/query.c"
#include "../CMS/read/showall.c"

// Define the commands table
Command commands[] = {
    {"help", cmd_help, "Display help menu"},
    {"exit", cmd_exit, "Exit program"},
    {"showall", showAll, "Display all records"},
    {"query",   query,   "Search for a record"}
};

// Define the number of commands
int num_commands = sizeof(commands) / sizeof(commands[0]);