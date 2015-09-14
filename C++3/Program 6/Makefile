# Project: Catching Plagiarists
# Makefile created by Dev-C++ 5.7.0

CPP      = g++
CC       = gcc
OBJ      = test.o hash.o array.o
LINKOBJ  = test.o hash.o array.o
BIN      = Project6
CXXFLAGS = $(CXXINCS) 
CFLAGS   = $(INCS) 
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o plagiarismCatcher $(LIBS)

test.o: test.cpp
	$(CPP) -c test.cpp -o test.o $(CXXFLAGS)

hash.o: hash.cpp
	$(CPP) -c hash.cpp -o hash.o $(CXXFLAGS)

array.o: array.cpp
	$(CPP) -c array.cpp -o array.o $(CXXFLAGS)
