#include "../include/vault.h"
#include "../include/files.h"
#include <stdint.h>

char *VAULT_PATH = "~/.slugpass/.spvault.spv";

bool create_vault() {
  int fd = create_file(VAULT_PATH);
  uint8_t magic_bytes[2] = {0xFA, 0xAF};

  if (fd > 0) {
    int status = write(fd, magic_bytes, sizeof(magic_bytes));
    close_file(fd);
    return true;
  }
  return false;
}
