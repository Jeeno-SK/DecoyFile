#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/inotify.h>
#include "logic.h"

#define EVENT_SIZE (sizeof(struct inotify_event))
#define BUF_LEN (1024 * (EVENT_SIZE + 16))

void start_monitor() {
    int fd = inotify_init();
    if (fd < 0) {
        perror("inotify_init");
        exit(1);
    }

    int wd = inotify_add_watch(fd, "decoy_files/", IN_OPEN);
    if (wd == -1) {
        perror("inotify_add_watch");
        exit(1);
    }

    char buffer[BUF_LEN];

    while (1) {
        int length = read(fd, buffer, BUF_LEN);

        if (length < 0) {
            perror("read");
            exit(1);
        }

        int i = 0;
        while (i < length) {
            struct inotify_event *event = 
                (struct inotify_event *) &buffer[i];

            if (event->len) {
                if (event->mask & IN_OPEN) {
                    handle_event(event->name);
                }
            }

            i += EVENT_SIZE + event->len;
        }
    }

    close(fd);
}
