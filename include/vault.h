#ifndef VAULT_H
#define VAULT_H

#include "files.h"
#include "version.h"
#include <arpa/inet.h>
#include <linux/limits.h>
#include <sodium.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
  uint8_t magic_bytes[4];
  uint32_t version;
  uint8_t salt[crypto_pwhash_SALTBYTES];
  uint8_t nonce[crypto_aead_xchacha20poly1305_ietf_NPUBBYTES];
} FileHeader;

typedef struct {
  int entry_index;
  char entry_title[255];
  char entry[255];
} VaultEntry;

typedef struct {
  VaultEntry entries[255];
} VaultBlob;

bool create_vault();
void gen_salt(uint8_t salt[crypto_pwhash_SALTBYTES]);
void gen_nonce(uint8_t nonce[crypto_aead_xchacha20poly1305_ietf_NPUBBYTES]);
void encrypt_vault();
void decrypt_vault();

#endif
