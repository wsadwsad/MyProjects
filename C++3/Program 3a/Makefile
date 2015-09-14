# Project: list_3358_arrays
# Makefile created by Dev-C++ 5.7.0
# Modified by Jie Zhou

CPP      = g++
CC       = gcc
OBJ      = list_3358_arrays.o list_test.o
LINKOBJ  = list_3358_arrays.o list_test.o
BIN      = list_3358_arrays
CXXFLAGS = $(CXXINCS) 
CFLAGS   = $(INCS) 
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o list_3358_arrays $(LIBS)

list_3358_arrays.o: list_3358_arrays.cpp
	$(CPP) -c list_3358_arrays.cpp -o list_3358_arrays.o $(CXXFLAGS)

list_test.o: list_test.cpp
	$(CPP) -c list_test.cpp -o list_test.o $(CXXFLAGS)
