GTK_LIB = `pkg-config --cflags --libs gtk+-3.0` -export-dynamic
OBJ = build/main_gtk.o build/widget_build.o build/body_main.o build/build_window.o  build/signals.o build/rendering.o build/main.o
CC = gcc
CFLAGS  = -g2 -Wall -Werror -std=c99

.PHONY: clean gtk console sh

bin/WordEng: $(OBJ) bin
	$(CC) $(CFLAGS) $(OBJ) -o bin/WordEng $(GTK_LIB)

build/body_main.o: src/body_main.c build #sh
	$(CC) $(CFLAGS) -c src/body_main.c -o build/body_main.o $(GTK_LIB)

build/main_gtk.o: src/gtk/main_gtk.c build #sh
	$(CC) $(CFLAGS) -c src/gtk/main_gtk.c -o build/main_gtk.o $(GTK_LIB)

build/widget_build.o: src/gtk/widget_build.c build #sh
	$(CC) $(CFLAGS) -c src/gtk/widget_build.c -o build/widget_build.o $(GTK_LIB)

build/signals.o: src/gtk/signals.c build #sh
	$(CC) $(CFLAGS) -c src/gtk/signals.c -o build/signals.o $(GTK_LIB)

build/rendering.o: src/gtk/rendering.c build #sh
	$(CC) $(CFLAGS) -c src/gtk/rendering.c -o build/rendering.o $(GTK_LIB)

build/build_window.o: src/gtk/build_window.c build #sh
	$(CC) $(CFLAGS) -c src/gtk/build_window.c -o build/build_window.o $(GTK_LIB)

build/main.o: src/main.c build #sh
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o $(GTK_LIB)

build:
	mkdir build

bin:
	mkdir bin

clean:
	rm -rf build bin

console :
	./bin/WordEng_console
gtk :
	gdb ./bin/WordEng
sh :
	sudo chmod +x packages.sh
	sudo ./packages.sh
