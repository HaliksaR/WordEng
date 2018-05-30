GTK_LIB = `pkg-config --cflags --libs gtk+-3.0` -export-dynamic
OBJ = build/main_gtk.o build/widget_build.o build/body_main.o build/build_window.o build/signals.o build/rendering.o build/check_global.o build/correct_start.o
OBJUI = $(OBJ) build/main_ui.o
OBJTRM = $(OBJ) build/logo.o build/main_console.o build/main.o
CC = gcc
CFLAGS  = -Wall -Werror -std=c99

.PHONY: clean gtk console sh icon delete

default: build bin bin/WordEng bin/WordEng_all

test: build bin bin/WordEng-test
	bin/WordEng-test

bin/WordEng: $(OBJUI)
	$(CC) $(CFLAGS) $(OBJUI) -o bin/WordEng $(GTK_LIB)

bin/WordEng_all: $(OBJTRM)
	$(CC) $(CFLAGS) $(OBJTRM) -o bin/WordEng_all $(GTK_LIB)
	
build/check_global.o: src/check_global.c
	$(CC) $(CFLAGS) -c src/check_global.c -o build/check_global.o

build/correct_start.o:
	$(CC) $(CFLAGS) -c src/correct_start.c -o build/correct_start.o $(GTK_LIB)

build/body_main.o: src/body_main.c
	$(CC) $(CFLAGS) -c src/body_main.c -o build/body_main.o $(GTK_LIB)

build/main_gtk.o: src/gtk/main_gtk.c
	$(CC) $(CFLAGS) -c src/gtk/main_gtk.c -o build/main_gtk.o $(GTK_LIB)

build/widget_build.o: src/gtk/widget_build.c
	$(CC) $(CFLAGS) -c src/gtk/widget_build.c -o build/widget_build.o $(GTK_LIB)

build/signals.o: src/gtk/signals.c
	$(CC) $(CFLAGS) -c src/gtk/signals.c -o build/signals.o $(GTK_LIB)

build/rendering.o: src/gtk/rendering.c
	$(CC) $(CFLAGS) -c src/gtk/rendering.c -o build/rendering.o $(GTK_LIB)

build/build_window.o: src/gtk/build_window.c
	$(CC) $(CFLAGS) -c src/gtk/build_window.c -o build/build_window.o $(GTK_LIB)

build/logo.o: src/console/logo.c
	$(CC) $(CFLAGS) -c src/console/logo.c -o build/logo.o $(GTK_LIB)

build/main_console.o: src/console/main_console.c
	$(CC) $(CFLAGS) -c src/console/main_console.c -o build/main_console.o $(GTK_LIB)

build/main.o: src/main.c
	$(CC) $(CFLAGS) -c src/main.c -o build/main.o $(GTK_LIB)

build/main_ui.o: src/main_ui.c
	$(CC) $(CFLAGS) -c src/main_ui.c -o build/main_ui.o $(GTK_LIB)

bin/WordEng-test: build/check_global.o build/correct_start.o build/main_test.o
	$(CC) $(CFLAGS) build/main_test.o build/check_global.o build/correct_start.o -o bin/WordEng-test

build/main_test.o: test/main.c thirdparty/ctest.h src/check_global.h src/correct_start.h
	$(CC) $(CFLAGS) -I thirdparty -c test/main.c -o build/main_test.o


build:
	mkdir build

bin:
	mkdir bin

clean:
	rm -rf build bin

console:
	./bin/WordEng_all

gtk:
	./bin/WordEng

icon: bin/WordEng
	chmod +x icon.sh
	./icon.sh
sh:
	chmod +x packages.sh
	sudo ./packages.sh

delete:
	chmod +x .rm_dir.sh
	./.rm_dir.sh
