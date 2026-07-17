#include "../include/files.h"

struct stat file_stat;

int open_file(char *file_path) {
  int fd = stat(file_path, &file_stat);

  if (fd >= 0) {
    if (!S_ISDIR(file_stat.st_mode)) {
      printf("File opened at %s", file_path);
      return fd;
    }
    fprintf(stderr, "Error: Path is a directory.\n");
    return -1;
  }
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
  int fd = creat(file_path, S_IRWXU);

  if (fd > 0) {
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
  return 1;
}

int create_directory(char *file_path) {
  int status = mkdir(file_path, S_IRWXU);

  if (status == 0) {
    return 0;
  }
  return -1;
}
