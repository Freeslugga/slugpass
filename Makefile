slugpass: src/main.c
	gcc -Wall -Wextra -Wshadow -fstack-protector -fPIE -s src/*.c -o out/slugpass

clean:
	rm out/*
