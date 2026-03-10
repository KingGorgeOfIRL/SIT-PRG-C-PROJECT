#ifndef COMMANDS_H
#define COMMANDS_H

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

// enter the functions to be used by main.c here
void loadStudents();

#endif