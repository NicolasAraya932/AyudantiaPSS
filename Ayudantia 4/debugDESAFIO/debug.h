#ifndef DEBUG_H
#define DEBUG_H

#include <stdio.h>
#include <stdarg.h>

#define DEBUG 1
#define INFO 2
#define ERROR 3

#define DEBUG_MODE 1

#define debug_message(level, format, ...) \
    do { \
        if (DEBUG_MODE) { \
            if (level == DEBUG) \
                printf("[DEBUG] In file: %s, line: %d: " format "\n", __FILE__, __LINE__, ##__VA_ARGS__); \
            else if (level == INFO) \
                printf("[INFO] In file: %s, line: %d: " format "\n", __FILE__, __LINE__, ##__VA_ARGS__); \
            else if (level == ERROR) \
                printf("[ERROR] In file: %s, line: %d: " format "\n", __FILE__, __LINE__, ##__VA_ARGS__); \
        } \
    } while(0)

#endif

