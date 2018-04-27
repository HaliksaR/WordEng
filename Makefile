GTK_LIB = `pkg-config --cflags --libs gtk+-3.0` -export-dynamic -no-pie 
OBJ = 
CC = gcc
CFLAGS  = -Wall -Werror

.PHONY: clean gtk console sh

./WordEng: ./build/main_gtk.o  bin
	$(CC) $(CFLAGS) ./build/main_gtk.o -o ./WordEng $(GTK_LIB)

./build/main_gtk.o: ./src/gtk/main_gtk.c  build #sh
	$(CC) $(CFLAGS) -c ./src/gtk/main_gtk.c -o ./build/main_gtk.o $(GTK_LIB)

build:
	mkdir build

bin:
	mkdir bin

clean:
	rm -rf build bin

console :
	./WordEng_console
gtk :
	./WordEng
sh :
	sudo chmod +x packages.sh
	sudo ./packages.sh