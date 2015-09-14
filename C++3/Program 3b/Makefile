# Project: list_3358_pointer
# Makefile created by Dev-C++ 5.7.0
# Modified by Jie Zhou

CPP      = g++
CC       = gcc
OBJ      = list_test.o list_3358_pointer.o
LINKOBJ  = list_test.o list_3358_pointer.o
BIN      = list_3358_pointer
CXXFLAGS = $(CXXINCS) 
CFLAGS   = $(INCS) 
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o $(BIN) $(LIBS)

list_test.o: list_test.cpp
	$(CPP) -c list_test.cpp -o list_test.o $(CXXFLAGS)

list_3358_pointer.o: list_3358_pointer.cpp
	$(CPP) -c list_3358_pointer.cpp -o list_3358_pointer.o $(CXXFLAGS)
