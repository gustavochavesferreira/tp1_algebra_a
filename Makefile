CC = g++
LIBS = -lm -lgmp
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/factorization.o $(OBJ)/miller_rabin.o $(OBJ)/generator.o $(OBJ)/powmod.o $(OBJ)/main.o 
HDRS = $(INC)/factorization.h $(INC)/miller_rabin.h $(INC)/generator.h $(INC)/powmod.h
CFLAGS = -Wall -c -I$(INC) 

EXE = $(BIN)/tp1.exe

run: $(EXE)
		$(EXE) 

$(BIN)/tp1.exe: $(OBJS)
	$(CC) -o $(BIN)/tp1.exe $(OBJS) $(LIBS)

$(OBJ)/factorization.o: $(HDRS) $(SRC)/factorization.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/factorization.o $(SRC)/factorization.cpp

$(OBJ)/miller_rabin.o: $(HDRS) $(SRC)/miller_rabin.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/miller_rabin.o $(SRC)/miller_rabin.cpp

$(OBJ)/generator.o: $(HDRS) $(SRC)/generator.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/generator.o $(SRC)/generator.cpp

$(OBJ)/powmod.o: $(HDRS) $(SRC)/powmod.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/powmod.o $(SRC)/powmod.cpp

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out *grind*