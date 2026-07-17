#ifndef FILES_H
#define FILES_H

#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int open_file(char *file_path);
bool does_file_exist(char *file_path);
int create_file(char *file_path);
int close_file(int file_descriptor);

#endif
