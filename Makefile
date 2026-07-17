slugpass: src/main.c
	gcc -Wall -Wextra -Wshadow -fstack-protector -fPIE -s src/main.c -o slugpass

clean:
	rm slugpass
