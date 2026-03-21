#ifndef READ_H
#define READ_H
 
// Student struct
struct Student {
    int id;
    char name[255];
    char programme[255];
    float mark;
};
 
// globals defined in open.c
extern struct Student students[100];
extern int studentCount;
 
// function declarations
int showAll();
void cmd_showall(char *args);
struct Student* query(int searchID);
void cmd_query(char *args);
 
#endif
 