CC			:= gcc
CFLAGS	:= -Wall -Wextra -Wshadow -Wconversion -fstack-protector-strong -fPIE -g -O1
LDFLAGS	:= -pie
LDLIBS	:= -Wl,-Bstatic -lsodium -Wl,-Bdynamic

SRCS		:= $(wildcard src/*.c)
BIN			:= out/slugpass

.PHONY: all clean
all: $(BIN)

$(BIN): $(SRCS) | out
	$(CC) $(CFLAGS) $(SRCS) -o $@ $(LDFLAGS) $(LDLIBS)

out:
	mkdir -p out

clean:
	rm -rf out
