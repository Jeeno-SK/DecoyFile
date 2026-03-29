#include <stdio.h>
#include "logic.h"

// Declare monitor function
void start_monitor();

int main() {
    printf("Starting Decoy File Monitoring System...\n");

    // Step 1: Load config
    load_config();

    // Step 2: Start monitoring
    start_monitor();

    return 0;
}