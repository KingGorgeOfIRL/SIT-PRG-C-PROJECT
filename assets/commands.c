#include "assets.h"
#include "../CMS/db/db_func.h"

// command table
Command commands[] = {
    {"help", cmd_help, "Display help menu"},
    {"exit", cmd_exit, "Exit program"},
    {"open", cmd_openStudents, "Load database file into memory"},
    {"save", cmd_saveStudents, "Save changes to database file"},
    {"insert", cmd_insert, "Insert new entry"},
    {"delete", cmd_delete, "Delete a record"},
    {"update", cmd_update, "Update a record"},
    {"show all", cmd_showall, "Display all records"},
    {"query", cmd_query, "Search for a record"}
};

// number of commands
int num_commands = sizeof(commands) / sizeof(commands[0]);