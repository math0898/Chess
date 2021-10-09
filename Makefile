# Mental reminder... '<target> : <prereqs>' Prerequirements can be listed as '<prereq> : <prereqs>'.
# Builds the chess.exe program. It probably doesn't use .exe encoding but it is executable is it not?
chess.exe : main.o pieces.h
	gcc main.o pieces.h -o chess.exe

# Builds main.o, with main.c as a prereq. -c means compile do not link. 
main.o : main.c
	gcc -c main.c

# Cleans the current directory of any partial or full builds of the executable. 
clean:
	@rm -f *.o
	@rm -f chess.exe