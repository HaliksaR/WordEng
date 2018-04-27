GTK_LIB = `pkg-config --cflags --libs gtk+-3.0` -export-dynamic
OBJ = 
CC = gcc
CFLAGS  = -Wall -Werror -std=c99

.PHONY: clean gtk console sh

bin/WordEng: build/main_gtk.o build/widget_build.o bin
	$(CC) $(CFLAGS) build/main_gtk.o build/widget_build.o -o bin/WordEng $(GTK_LIB)

build/main_gtk.o: src/gtk/main_gtk.c  build #sh
	$(CC) $(CFLAGS) -c src/gtk/main_gtk.c -o build/main_gtk.o $(GTK_LIB)

build/widget_build.o: src/gtk/widget_build.c build
	$(CC) $(CFLAGS) -c src/gtk/widget_build.c -o build/widget_build.o $(GTK_LIB)

build:
	mkdir build

bin:
	mkdir bin

clean:
	rm -rf build bin

console :
	./bin/WordEng_console
gtk :
	./bin/WordEng
sh :
	sudo chmod +x packages.sh
	sudo ./packages.sh
