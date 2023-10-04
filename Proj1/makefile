# makefile
CC = g++
CFLAGS = -c
# -c option ask g++ to compile the source files, but do not link.
#  # -g option is for debugging version
# -O2 option is for optimized version
DBGFLAGS = -g -D_DEBUG_ON_ -Wall
OPTFLAGS = -O2

all : bin/TSP_Solver

# optimized version
bin/TSP_Solver : solve_tool_opt.o main_opt.o
	$(CC) $(OPTFLAGS) solve_tool_opt.o main_opt.o -o bin/TSP_Solver

main_opt.o : src/main.cpp
	$(CC) $(CFLAGS) $< -o $@

solve_tool_opt.o : src/solve_tool.cpp src/solve_tool.h
	$(CC) $(CFLAGS) $(OPTFLAGS) $< -o $@

# clean all the .o and executable file
clean :
	rm -rf *.o bin/*
