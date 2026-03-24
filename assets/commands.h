#ifndef COMMANDS_H
#define COMMANDS_H

// Forward declare Command struct so other files can include this
typedef struct {
    const char *name;
    void (*func)(char *args);
    const char *description;
} Command;

//struct Student is defined here, so there is no need to add this to other files
struct Student 
{
    int id;
    char name[255];
    char programme[255];
    float mark;
};

//extern tells the compiler to find these variables in open.c
extern struct Student students[100];
extern int studentCount;


// Declare the commands table and its size
extern Command commands[];
extern int num_commands;

#endif