#ifndef READ_H
#define READ_H

#include "../include/commands.h"

int showAll();
void cmd_showall();
struct Student* query(int searchID);
void cmd_query();

#endif