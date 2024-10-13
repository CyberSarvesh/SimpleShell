// builtins.c
#include "builtins.h"
#include <stdio.h>
#include <unistd.h>  // For chdir()

void change_directory(char *path) {
    if (chdir(path) != 0) {
        perror("cd failed");
    }
}

void shell_exit() {
    printf("Exiting shell.\n");
    _exit(0);  // Use _exit for a direct exit
}

void print_help() {
    printf("Help: Supported commands include cd, exit, and help.\n");
}
