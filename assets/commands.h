#ifndef COMMANDS_H
#define COMMANDS_H

// Forward declare Command struct so other files can include this
typedef struct {
    const char *name;
    void (*func)();
    const char *description;
} Command;

// Declare the commands table and its size
extern Command commands[];
extern int num_commands;

#endif