#include "../include/files.h"
#include <fcntl.h>

int open_file(char *file_path) {
  int file_open = open(file_path, O_RDWR);

  if (file_open >= 0) {
    return file_open;
  }
  fprintf(stderr, "Error: Could not open file at: %s: %s", file_path,
          strerror(errno));
  return -1;
}

bool does_file_exist(char *file_path) {
  int ok = access(file_path, F_OK);

  if (ok == 0) {
    return true;
  }
  return false;
}

int create_file(char *file_path) {
  int fd = open(file_path, O_WRONLY | O_CREAT | O_EXCL, S_IRUSR | S_IWUSR);

  if (fd >= 0) {
    return fd;
  }
  fprintf(stderr, "Error: Could not create file at: %s: %s\n", file_path,
          strerror(errno));
  return -1;
}

int close_file(int file_descriptor) {
  int status = close(file_descriptor);

  if (status == 0) {
    return 0;
  }
  return -1;
}

int create_directory(char *file_path) {
  int status = mkdir(file_path, S_IRWXU);

  if (status == 0) {
    return 0;
  }
  return -1;
}

bool does_dir_exist(char *file_path) {
  struct stat file_stat;
  int status = stat(file_path, &file_stat);

  if (status == 0) {
    if (S_ISDIR(file_stat.st_mode)) {
      return true;
    }
    fprintf(stderr, "Error: File at path %s is not a directory.\n", file_path);
    return false;
  }
  return false;
}
