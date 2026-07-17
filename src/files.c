#include "../include/files.h"

struct stat file_stat;

int open_file(char *file_path[]) {
  int fd = stat(*file_path, &file_stat);

  if (fd >= 0) {
    if (!S_ISDIR(file_stat.st_mode)) {
      printf("File opened at %s", *file_path);
      return fd;
    }
    fprintf(stderr, "Error: Path is a directory.\n");
    return -1;
  }
  return -1;
}
