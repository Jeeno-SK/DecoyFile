#include <stdio.h>
#include <string.h>
#include <time.h>
#include "logic.h"

char decoy_files[MAX_FILES][MAX_LEN];
int file_count = 0;
int access_count = 0;

// Load config file
void load_config() {
    FILE *fp = fopen("config/config.txt", "r");
    if (fp == NULL) {
        printf("Error opening config file\n");
        return;
    }

    while (fgets(decoy_files[file_count], MAX_LEN, fp)) {
        // Remove newline
        decoy_files[file_count][strcspn(decoy_files[file_count], "\n")] = 0;
        file_count++;
    }

    fclose(fp);
    printf("Config loaded. %d files monitored.\n", file_count);
}

// Check if file is decoy
int is_decoy_file(char *filename) {
    for (int i = 0; i < file_count; i++) {
        // Compare only filename part
        if (strstr(decoy_files[i], filename) != NULL) {
            return 1;
        }
    }
    return 0;
}

// Increment counter
void increment_counter() {
    access_count++;
}

// Check threshold
int check_threshold() {
    if (access_count >= 3) {
        return 1;
    }
    return 0;
}

// Log event
void log_event(char *filename) {
    FILE *fp = fopen("logs/log.txt", "a");
    if (fp == NULL) {
        printf("Error opening log file\n");
        return;
    }

    time_t now = time(NULL);
    fprintf(fp, "ALERT: %s accessed at %s", filename, ctime(&now));
    fclose(fp);

    printf("ALERT logged for %s\n", filename);
}

// Handle event
void handle_event(char *filename) {
    printf("File accessed: %s\n", filename);

    if (is_decoy_file(filename)) {
        increment_counter();

        if (check_threshold()) {
            log_event(filename);
        }
    }
}