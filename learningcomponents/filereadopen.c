
//simple file reading and file opening code
#include <fcntl.h>  // For open()
#include <unistd.h> // For read(), write(), close()
#include <stdio.h>
#include <string.h>

int main() {
    char buffer[100];
    int fd = open("file.txt", O_RDONLY); // Open a file in read-only mode
    if (fd < 0) {
        printf("Error opening file\n");
        return 1;
    }

    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead < 0) {
        printf("Error reading file\n");
        return 1;
    }

    buffer[bytesRead] = '\0';  // Null-terminate the string
    printf("File contents: %s\n", buffer);

    close(fd);  // Close the file
    return 0;
}
