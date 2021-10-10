# Mental reminder... '<target> : <prereqs>' Prerequirements can be listed as '<prereq> : <prereqs>'.
# Builds the chess.exe program. It probably doesn't use .exe encoding but it is executable is it not?
chess.exe : main.o game.o input.o pieces.h
	gcc main.o game.o input.o pieces.h -o chess.exe

# Builds main.o, with main.c as a prereq. -c means compile do not link. 
main.o : main.c pieces.h
	gcc -c main.c

game.o : game.c pieces.h
	gcc -c game.c

input.o : game.c
	gcc -c input.c

# Cleans the current directory of any partial or full builds of the executable. 
clean:
	@rm -f *.o
	@rm -f chess.exe
	@rm -f pieces.h.gch
	@rm -f debug.exe

# Builds a debugging version of the executable and runs it using gdb.
debug:
	gcc -g -c game.c
	gcc -g -c main.c
	gcc -g -c input.c
	gcc main.o game.o input.o pieces.h -g -o debug.exe
	@gdb ./debug.exe

# Clean builds the program by removing artifacts from the previous build and starting a new one.
cleanbuild : clean chess.exe