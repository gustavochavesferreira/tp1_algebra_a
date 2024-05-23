CC = g++
LIBS = -lm -lgmp
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/miller_rabin.o $(OBJ)/main.o 
HDRS = $(INC)/miller_rabin.h
CFLAGS = -Wall -c -I$(INC) 

EXE = $(BIN)/tp1.exe

run: $(EXE)
		$(EXE) 

$(BIN)/tp1.exe: $(OBJS)
	$(CC) -o $(BIN)/tp1.exe $(OBJS) $(LIBS)

$(OBJ)/miller_rabin.o: $(HDRS) $(SRC)/miller_rabin.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/miller_rabin.o $(SRC)/miller_rabin.cpp

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out *grind*