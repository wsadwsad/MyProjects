# Project: Flood Fill
# Makefile created by Dev-C++ 5.7.0

CPP      = g++
OBJ      = flood_fill.o
LINKOBJ  = flood_fill.o
BIN      = Flood Fill
CXXFLAGS = $(CXXINCS) 
CFLAGS   = $(INCS) 
RM       = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before $(BIN) all-after

clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o flood_fill $(LIBS)

flood_fill.o: flood_fill.cpp
	$(CPP) -c flood_fill.cpp -o flood_fill.o $(CXXFLAGS)
