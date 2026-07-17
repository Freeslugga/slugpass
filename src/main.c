#include <stdio.h>
#include <string.h>
#include "../include/files.h"

int main(int argc, char *argv[]) {
  if (argc > 1 && strcmp(argv[1], "vault") == 0) {
    // ./slugpass vault
    if (argc == 3 && strcmp(argv[2], "init") == 0) {
      // ./slugpass vault init
      printf("Initializing vault file in CWD.\n");
      return 0;
    }
  }

  if (argc == 1) {
    fprintf(stderr, "Error: Usage ./slugpass <command> <subcommand>\n");
    return 1;
  }
  return 1;
}
