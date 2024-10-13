// fileops.c
#include "fileops.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>  // Ensure strlen is included

int open_file(const char *filename, int flags) {
    int fd = open(filename, flags);
    if (fd == -1) {
        perror("Error opening file");
        return -1;
    }
    return fd;
}

void read_file(int fd) {
    char buffer[1024];
    ssize_t bytes_read;
    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }
    if (bytes_read == -1) {
        perror("Error reading file");
    }
}

void write_to_file(int fd, const char *data) {
    ssize_t bytes_written = write(fd, data, strlen(data));  // Ensure strlen is used here
    if (bytes_written == -1) {
        perror("Error writing to file");
    }
}

void close_file(int fd) {
    if (close(fd) == -1) {
        perror("Error closing file");
    }
}
