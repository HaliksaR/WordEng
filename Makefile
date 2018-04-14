GTK_LIB = `pkg-config --cflags --libs gtk+-3.0` -no-pie
OBJ = 
CC = gcc
CFLAGS  = -Wall -Werror

.PHONY: clean gtk console sh

./bin/WordEng: ./build/main_gtk.o  bin
	$(CC) $(CFLAGS) ./build/main_gtk.o -o ./bin/WordEng $(GTK_LIB)

./build/main_gtk.o: src/main_gtk.c  build #sh
	$(CC) $(CFLAGS) -c ./src/main_gtk.c -o ./build/main_gtk.o $(GTK_LIB)

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