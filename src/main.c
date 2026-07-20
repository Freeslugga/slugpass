#include "../include/vault.h"
#include <sodium.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int stat = sodium_init();

  if (stat == 0 || stat == 1) {
    if (argc > 1 && strcmp(argv[1], "vault") == 0) {
      // ./slugpass vault
      if (argc == 3 && strcmp(argv[2], "init") == 0) {
        // ./slugpass vault init
        printf("Initializing vault file in CWD.\n");
        create_vault();
        return 0;
      }
    }
  } else {
    fprintf(stderr, "Error: Sodium could not initialize.\n");
    return 1;
  }

  if (argc == 1) {
    fprintf(stderr, "Error: Usage ./slugpass <command> <subcommand>\n");
    return 1;
  }
  return 1;
}
