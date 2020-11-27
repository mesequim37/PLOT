FLAGS0 = -O0
FLAGS2 = -O2
FLAGS3 = -O3

OBJECTS = heatExp.c tools.c 
OBJECTS2 = implicit.c tools.c 

BIN1 = heatEx
BIN2 = heatIm
BIN3 = solvedebug

all: $(BIN1)

heatEx: $(OBJECTS)
	gcc -o $(BIN1) $(FLAGS3) $(OBJECTS)

heatIm: $(OBJECTS)
	gcc -o $(BIN2) $(FLAGS3) $(OBJECTS2)
	
solvedebug: $(OBJECTS) 
	gcc -g -o $(BIN3) $(FLAGS0) $(OBJECTS)


