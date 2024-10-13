// fileops.h
#ifndef FILEOPS_H
#define FILEOPS_H

int open_file(const char *filename, int flags);
void read_file(int fd);
void write_to_file(int fd, const char *data);
void close_file(int fd);

#endif
