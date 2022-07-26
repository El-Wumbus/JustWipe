CC=gcc
CFLAGS=-Wall -Werror
CFILES=$(wildcard src/*.c)
EXE=build/jwipe
defualt: build


build: clean
	mkdir -p build
	$(CC) $(CFLAGS) -o $(EXE) $(CFILES)

install: build
	mkdir -p ${DESTDIR}${PREFIX}/usr/local/bin/
	mkdir -p ${DESTDIR}${PREFIX}/usr/local/share/doc/jwipe/
	install -Dm755 $(EXE) ${DESTDIR}${PREFIX}/usr/local/bin/jwipe
	install -Dm644 README.md ${DESTDIR}${PREFIX}/usr/local/share/doc/jwipe/README.md
	install -Dm644 LICENSE.md ${DESTDIR}${PREFIX}/usr/local/share/doc/jwipe/LICENSE.md

uninstall:
	rm -rf ${DESTDIR}${PREFIX}/usr/local/bin/jwipe
	rm -rf ${DESTDIR}${PREFIX}/usr/local/share/doc/jwipe

clean:
	rm -rf build

run: build
	./$(EXE)