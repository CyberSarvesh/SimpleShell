#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void print_current_directory() {
    char cwd[1024]; // Buffer to store current directory
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Current Directory: %s\n", cwd);
    } else {
        perror("getcwd() error");
    }
}

void change_directory(char *path) {
    // Change the current working directory
    if (chdir(path) != 0) {
        perror("cd failed"); // Print error if chdir fails
    }
}

int main() {
    // Print current directory before changing
    print_current_directory();
    
    char *path = ".."; // Example path to go up one level
    change_directory(path); // Change to the specified directory
    
    // Print current directory after changing
    print_current_directory();
    
    return 0;
}
