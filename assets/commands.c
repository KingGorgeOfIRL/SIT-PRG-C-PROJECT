#include "commands.h"
#include "../CMS/commands/db_func.h"
#include "../CMS/insert/insert_func.h"
#include "../CMS/read/read.h"
#include "../CMS/IO/io.h"

// command table
Command commands[] = {
    {"help", cmd_help, "Display help menu"},
    {"exit", cmd_exit, "Exit program"},
    {"insert", cmd_insert, "Insert new entry"},
    {"showall", cmd_showall, "Display all records"},
    {"query",   cmd_query,   "Search for a record"},
    {"open",   cmd_loadStudents,   "Opens the database file and read in all the records"},
    {"save",   cmd_saveStudents,   "Saves all the current records into the database file"}

};

// number of commands
int num_commands = sizeof(commands) / sizeof(commands[0]);