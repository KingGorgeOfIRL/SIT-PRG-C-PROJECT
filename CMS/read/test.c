#include <stdio.h>
#include <string.h>
#include "../include/commands.h"


struct Student students[100];
int studentCount = 0;

int main() {
    //fake student records
    students[0].id = 2301234;
    strcpy(students[0].name, "Joshua Chen");
    strcpy(students[0].programme, "Software Engineering");
    students[0].mark = 70.5;

    students[1].id = 2201234;
    strcpy(students[1].name, "Isaac Teo");
    strcpy(students[1].programme, "Computer Science");
    students[1].mark = 63.4;

    students[2].id = 2304567;
    strcpy(students[2].name, "John Levoy");
    strcpy(students[2].programme, "Digital Supply Chain");
    students[2].mark = 85.9;

    studentCount = 3;

    //test SHOW ALL
    printf("=== Testing SHOW ALL ===\n");
    showAll();

    //test QUERY
    printf("=== Testing QUERY ===\n");
    query();

    return 0;
}
