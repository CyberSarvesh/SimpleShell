#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>  // For O_RDONLY
#include <unistd.h> // For close
#include "builtins.h"
#include "fileops.h"

#define MAX_INPUT_SIZE 1024
#define MAX_CMD_SIZE 100

void execute_command(char *command) {
    char *args[MAX_CMD_SIZE];
    char *token = strtok(command, " ");
    int i = 0;

    while (token != NULL && i < MAX_CMD_SIZE - 1) {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;  // NULL-terminate the argument list

    if (strcmp(args[0], "cd") == 0) {
        // Change directory command
        if (i > 1) {
            change_directory(args[1]);
        } else {
            fprintf(stderr, "cd: missing argument\n");
        }
    } else if (strcmp(args[0], "exit") == 0) {
        // Exit the shell
        shell_exit();
    } else if (strcmp(args[0], "help") == 0) {
        // Print help message
        print_help();
    } else if (strcmp(args[0], "ofile") == 0) {
        if (i > 1) {
            int fd = open_file(args[1], O_RDONLY);
            if (fd != -1) {
                printf("File opened successfully: %s\n", args[1]);
                close(fd);  // Remember to close the file descriptor
            } else {
                fprintf(stderr, "Could not open file: %s\n", args[1]);
            }
        } else {
            fprintf(stderr, "ofile: missing argument\n");
        }
    } else {
        // Handle other commands (e.g., file operations)
        fprintf(stderr, "Command not found: %s\n", args[0]);
    }
}

int main() {
    char input[MAX_INPUT_SIZE];

    while (1) {
        printf("my_shell> ");  // Shell prompt
        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("fgets failed");
            continue;  // If reading fails, continue to next iteration
        }

        // Remove newline character from input
        input[strcspn(input, "\n")] = 0;

        execute_command(input);
    }

    return 0;
}
