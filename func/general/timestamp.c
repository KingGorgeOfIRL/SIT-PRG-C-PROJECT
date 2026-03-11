#include "timestamp.h"
#include <time.h>

// Current Timestamp
// buffer -> pointer to timestamp
// size -> size of buffer
void get_timestamp(char *buffer, size_t size) {

    // get current time (epoch)
    time_t now = time(NULL);

    // convert epoch to redable
    struct tm *t = localtime(&now);

    // format time & store in buffer
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", t);
}