#include <stdio.h>
#include <string.h>
#include "read.h"


// returns a pointer to the matching student record, or NULL if not found.
struct Student* query(int searchID) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == searchID) {
            return &students[i];
        }
    }
    return NULL;
}
 