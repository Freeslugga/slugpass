#include "../include/vault.h"
#include "../include/files.h"

bool create_vault() {
  const char *HOME = getenv("HOME");
  char VAULT_PATH[PATH_MAX];
  snprintf(VAULT_PATH, sizeof(VAULT_PATH), "%s/.slugpass", HOME);
  char VAULTFILE_PATH[PATH_MAX];
  int n = snprintf(VAULTFILE_PATH, sizeof(VAULTFILE_PATH), "%s/.spvault.spv",
                   VAULT_PATH);
  if (n < 0 || (size_t)n >= sizeof(VAULTFILE_PATH)) {
    fprintf(stderr, "Error: File Path exceeds max length");
    return false;
  }
  uint8_t magic_bytes[2] = {0xFA, 0xAF};

  printf("Path: %s\n", VAULT_PATH);

  if (!does_dir_exist(VAULT_PATH)) {
    int dfd = create_directory(VAULT_PATH);

    if (dfd < 0) {
      return false;
    }
  }

  int fd = create_file(VAULTFILE_PATH);

  if (fd > 0) {
    int status = write(fd, magic_bytes, sizeof(magic_bytes));
    close_file(fd);
    return true;
  }
  return false;
}
