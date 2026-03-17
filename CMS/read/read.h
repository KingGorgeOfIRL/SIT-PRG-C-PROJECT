#ifndef READ_H
#define READ_H

struct Student 
{
    int id;
    char name[255];
    char programme[255];
    float mark;
};

extern struct Student students[100];
extern int studentCount;

int showAll();
struct Student* query(int searchID);

#endif
