# Project: Tree Search
# Makefile created by Dev-C++ 5.7.0

CPP      = g++
CC       = gcc

OBJ      = test.o
LINKOBJ  = test.o
BIN      = "Tree Search.exe"
CXXFLAGS = $(CXXINCS) 
CFLAGS   = $(INCS) 
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o test $(LIBS)

test.o: test.cpp
	$(CPP) -c test.cpp -o test.o $(CXXFLAGS)
