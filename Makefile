CC=gcc
CFLAGS=-Wall -Werror -lncurses -lmenu
CFILES=$(wildcard src/*.c)
# CFILES=src/main.c
EXE=build/jwipe
defualt: build


build: clean
	mkdir -p build
	$(CC) $(CFLAGS) -o $(EXE) $(CFILES)

clean:
	rm -rf build

run: build
	./$(EXE)