GTK_LIB = `pkg-config --cflags --libs gtk+-3.0` -export-dynamic -no-pie
OBJ = 
CC = gcc
CFLAGS  = -g2 -Wall -Werror -std=c99

.PHONY: clean gtk console sh

bin/WordEng: build/main_gtk.o build/widget_build.o build/body_main.o build/main.o bin
	$(CC) $(CFLAGS) build/main_gtk.o build/widget_build.o build/body_main.o build/main.o -o bin/WordEng $(GTK_LIB)

build/body_main.o: src/body_main.c build #sh
	$(CC) $(CFLAGS) -c src/body_main.c -o build/body_main.o $(GTK_LIB)

build/console_graphics.o: src/console/console_graphics.c build #sh
	$(CC) $(CFLAGS) -c src/console/console_graphics.c -o build/console_graphics.o $(GTK_LIB)

build/logo.o: src/console/logo.c build #sh
	$(CC) $(CFLAGS) -c src/console/logo.c -o build/logo.o $(GTK_LIB)

build/main.o: src/main.c build #sh
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o $(GTK_LIB)

build:
	mkdir build

bin:
	mkdir bin

clean:
	rm -rf build bin

console:
	./bin/WordEng_console
gtk :
	gdb ./bin/WordEng
sh :
	sudo chmod +x packages.sh
	sudo ./packages.sh
