#include "read.h"

// 🔹 Define the actual globals (ONLY here)
struct Student students[100];
int studentCount = 0;

// 🔹 query function
struct Student* query(int searchID) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == searchID) {
            return &students[i];
        }
    }
    return 0;
}