#include <stdio.h>
#include <stdarg.h>
#include "debug.h"

int main() {
    debug_message(DEBUG, "This is a debug message.");
    debug_message(INFO, "This is an info message.");
    debug_message(ERROR, "This is an error message.");

    return 0;
}

