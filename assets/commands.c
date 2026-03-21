#include "commands.h"
#include "../CMS/commands/db_func.h"
#include "../CMS/insert/insert_func.h"
#include "../CMS/read/read.h"

// command table
Command commands[] = {
    {"help", cmd_help, "Display help menu"},
    {"exit", cmd_exit, "Exit program"},
    {"insert", cmd_insert, "Insert new entry"},
    {"showall", cmd_showall, "Display all records"},
    {"query",   cmd_query,   "Search for a record"}

};

// number of commands
int num_commands = sizeof(commands) / sizeof(commands[0]);