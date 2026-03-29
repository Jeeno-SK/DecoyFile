#ifndef LOGIC_H
#define LOGIC_H

#define MAX_FILES 100
#define MAX_LEN 256

// Global storage
extern char decoy_files[MAX_FILES][MAX_LEN];
extern int file_count;
extern int access_count;

// Functions
void load_config();
void handle_event(char *filename);
int is_decoy_file(char *filename);
void increment_counter();
int check_threshold();
void log_event(char *filename);

#endif