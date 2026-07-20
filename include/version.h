#ifndef VERSION_H
#define VERSION_H

#include <stdint.h>

#define VERSION_MAJOR 0
#define VERSION_MINOR 1
#define VERSION_PATCH 6

#define PACKED_APP_VERSION                                                     \
  ((VERSION_MAJOR << 24) | (VERSION_MINOR << 16) | VERSION_PATCH)

#endif
