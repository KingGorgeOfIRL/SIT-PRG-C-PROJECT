#ifndef COMMANDS_H
#define COMMANDS_H

// Forward declare Command struct so other files can include this
typedef struct {
    const char *name;
    void (*func)(char *args);
    const char *description;
} Command;

//struct Student is defined here, so there is no need to add this to other files
typedef struct Student{
    int id;
    char name[255];
    char programme[255];
    float mark;
}Student;

// array of list pointers, index
typedef struct Record{
    Student *node;
}Record;

// global var
extern Record *records;
extern int recordCount;
extern int recordCapacity;
extern struct Student students[100];
extern int studentCount;
extern Command commands[];
extern int num_commands;

// utility functions
extern int binary_search(Record *student_record, int *count, int id);
extern int insert(Record **student_record, int *count, int capacity, int position, int id, const char *name, const char *programme, float mark);


#endif