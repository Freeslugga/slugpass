#include "../include/vault.h"

bool create_vault() {
  uint32_t safe_version = htonl(PACKED_APP_VERSION);
  FileHeader header = {{0xFA, 0xAF}, safe_version};
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

  if (!does_dir_exist(VAULT_PATH)) {
    int dfd = create_directory(VAULT_PATH);

    if (dfd < 0) {
      return false;
    }
  }

  int fd = create_file(VAULTFILE_PATH);

  if (fd > 0) {
    ssize_t status = write(fd, &header, sizeof(header));
    close_file(fd);
    return true;
  }
  return false;
}
