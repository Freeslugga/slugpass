#ifndef VAULT_H
#define VAULT_H

#include "files.h"
#include "version.h"
#include <arpa/inet.h>
#include <linux/limits.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct {
  uint8_t magic_bytes[2];
  uint32_t version;
} FileHeader;

bool create_vault();

#endif
