#ifndef SANITIZE_INPUT_H
#define SANITIZE_INPUT_H

#include <stddef.h>

// Reads input from stdin, trims newline, lowercases, and ensures max length.
// Returns 1 on success, 0 on failure (input too long or fgets error).
int sanitize_input(char *buffer, size_t size);

#endif // SANITIZE_INPUT_H