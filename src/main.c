#include <stdio.h>
#include "logic.h"


void start_monitor();

int main() {
    printf("Starting Decoy File Monitoring System...\n");


    load_config();


    start_monitor();

    return 0;
}
