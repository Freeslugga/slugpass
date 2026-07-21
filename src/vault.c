#include "../include/vault.h"

bool create_vault() {
  uint32_t safe_version = htonl(PACKED_APP_VERSION);
  FileHeader header = {{0x7F, 0x53, 0x50, 0x56}, safe_version};
  gen_salt(header.salt);
  gen_nonce(header.nonce);
  const char *HOME = getenv("HOME");
  char VAULT_PATH[PATH_MAX];
  snprintf(VAULT_PATH, sizeof(VAULT_PATH), "%s/.slugpass", HOME);
  char VAULTFILE_PATH[PATH_MAX];
  int n = snprintf(VAULTFILE_PATH, sizeof(VAULTFILE_PATH), "%s/.spvault.spv",
                   VAULT_PATH);
  if (n < 0 || (size_t)n >= sizeof(VAULTFILE_PATH)) {
    fprintf(stderr, "Error: File Path exceeds max length.\n");
    return false;
  }

  if (!does_dir_exist(VAULT_PATH)) {
    int dfd = create_directory(VAULT_PATH);

    if (dfd < 0) {
      return false;
    }
  }

  int fd = create_file(VAULTFILE_PATH);

  if (fd >= 0) {
    ssize_t status = write(fd, &header, sizeof(header));
    close_file(fd);
    return true;
  }
  return false;
}

void gen_salt(uint8_t salt[crypto_pwhash_SALTBYTES]) {
  randombytes_buf(salt, crypto_pwhash_SALTBYTES);
}

void gen_nonce(uint8_t nonce[crypto_aead_xchacha20poly1305_ietf_NPUBBYTES]) {
  randombytes_buf(nonce, crypto_aead_xchacha20poly1305_ietf_NPUBBYTES);
}
