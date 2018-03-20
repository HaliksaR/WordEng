COMPILE_FLAGS = -g3 -O0
GTK_LIB = `pkg-config --cflags --libs gtk+-3.0`
OBJ = ./build/main.o ./build/global_arguments.o ./build/file_processing.o ./build/array_processing.o ./build/interface.o

bin :
	mkdir bin

build :
	mkdir build
		
./bin/WordEng_console : $(OBJ)
		gcc $(COMPILE_FLAGS) -o ./bin/calcFrequency $(OBJ)
./bin/WordEng : $(OBJ)
		gcc $(COMPILE_FLAGS) -o ./bin/calcFrequency $(OBJ) $(GTK_LIB)

./build/main.o : ./src/main.c ./src/global_arguments.h ./src/file_processing.h ./src/array_processing.h ./src/interface.h
		gcc $(COMPILE_FLAGS) -o ./build/main.o -c ./src/main.c

./build/global_arguments.o : ./src/global_arguments.c ./src/global_arguments.h
		gcc $(COMPILE_FLAGS) -o ./build/global_arguments.o -c ./src/global_arguments.c 

./build/file_processing.o : ./src/file_processing.c ./src/file_processing.h
		gcc $(COMPILE_FLAGS) -o ./build/file_processing.o -c ./src/file_processing.c

./build/array_processing.o : ./src/array_processing.c ./src/array_processing.h
		gcc $(COMPILE_FLAGS) -o ./build/array_processing.o -c ./src/array_processing.c

./build/interface.o : ./src/interface.c ./src/interface.h
		gcc $(COMPILE_FLAGS) -o ./build/interface.o -c ./src/interface.c 



.PHONY: clean open gdb_ngtk gdb_gtk gcc console

console :
		./bin/WordEng_console
open :
		./bin/WordEng
gdb_ngtk :
		gdb ./bin/WordEng_console
gdb_gtk :		
		gdb ./bin/WordEng
clean :
		rm -rf ./build/ ./bin/
