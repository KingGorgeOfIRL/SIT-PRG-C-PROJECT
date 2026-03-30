#include "assets.h"
#include <stdlib.h>
#include <string.h>

// dynamic database globals
Record *records = 0;
int recordCount = 0;
int recordCapacity = 0;

// static array (if still used by older commands)
struct Student students[100];
int studentCount = 0;
