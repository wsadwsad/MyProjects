# Project: Equation Checker
# Makefile created by Dev-C++ 5.7.0
# Modified by Jie Zhou

CPP      = g++
OBJ      = equation_test.o
LINKOBJ  = equation_test.o
BIN      = Equation Checker
CXXFLAGS = $(CXXINCS) 
CFLAGS   = $(INCS) 
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o equation_test $(LIBS)

equation_test.o: equation_test.cpp
	$(CPP) -c equation_test.cpp -o equation_test.o $(CXXFLAGS)
