GTK_LIB = `pkg-config --cflags --libs gtk+-3.0` -export-dynamic -no-pie
OBJ = 
CC = gcc
CFLAGS  = -Wall -Werror -std=c99

.PHONY: clean gtk console sh

bin/WordEng_console: build/console_graphics.o build/logo.o build/body_main.o bin
	$(CC) $(CFLAGS) build/console_graphics.o build/logo.o build/body_main.o -o bin/WordEng_console $(GTK_LIB)

build/body_main.o: src/body_main.c build #sh
	$(CC) $(CFLAGS) -c src/body_main.c -o build/body_main.o $(GTK_LIB)

build/console_graphics.o: src/console/console_graphics.c build #sh
	$(CC) $(CFLAGS) -c src/console/console_graphics.c -o build/console_graphics.o $(GTK_LIB)

build/logo.o: src/console/logo.c build #sh
	$(CC) $(CFLAGS) -c src/console/logo.c -o build/logo.o $(GTK_LIB)

build:
	mkdir build

bin:
	mkdir bin

clean:
	rm -rf build bin

console:
	./bin/WordEng_console
gtk:
	./bin/WordEng
sh:
	sudo chmod +x packages.sh
	sudo ./packages.sh
