#ifndef READ_H
#define READ_H

// Define the Student struct (must match your actual definition)
struct Student {
    int id;
    char name[100];
    char programme[100];
    float mark;
};

// Declare the query function
struct Student* query(int searchID);

#endif