#ifndef UTILITIES_H
#define UTILITIES_H

#include <stddef.h>
#include "../../assets/assets.h"

// Reads input from stdin, trims newline, lowercases, and ensures max length.
// Returns 1 on success, 0 on failure (input too long or fgets error).
int sanitize_input(char *buffer, size_t size, int to_lowercase);

// Writes a formatted timestamp string into buffer.
void get_timestamp(char *buffer, size_t size);

int binary_search(Record *student_record, int *count, int id);

#endif