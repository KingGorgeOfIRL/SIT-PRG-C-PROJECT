#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// linked list to store student details
typedef struct Student{
    int id;
    char name[255];
    char programme[255];
    float mark;
}Student;

// array of linked list pointers, point to the first node of every 10 IDs
typedef struct Record{
    Student *node;
}Record;

// returns position if found and sorted, expected position if not found 
int binary_search(Record *student_record,int *count, int id);

// assumes that student is not in record
int insert(Record **student_record, int *capacity, int *count, int position, int id, const char *name, const char *programme,float mark);

// open IO function to read from txt file
Record *openfile(const char *file_path, char err_msg[255], int *count);

// returns student id if there is an error, assumes that student is in record
int update(Record *student_record, int size_of_array, int position, Student *new_data);

// returns student id if there is an error, assumes that student is in record
int remove(int position, Record *student_record,int size_of_array);