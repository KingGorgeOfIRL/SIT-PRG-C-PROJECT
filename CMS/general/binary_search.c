#include "general_func.h"
#include "../../assets/assets.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// returns position if found and sorted, expected position if not found
int binary_search(Record *student_record, int *count, int id) {
    int low = 0;
    int high = *count - 1;

    while (low <= high) {
        int position = low + (high - low) / 2;
        int current_id = student_record[position].node->id;
        if (current_id == id) {
            return position;
        } else if (current_id < id) {
            low = position + 1;
        } else {
            high = position - 1;
        }
    }
    return low;
}