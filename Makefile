CC = g++
LIBS = -lm -lgmp
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/factorization.o $(OBJ)/prime_generator.o $(OBJ)/miller_rabin.o $(OBJ)/generator.o $(OBJ)/crt.o $(OBJ)/bsgs.o $(OBJ)/pohlig_hellman.o $(OBJ)/naive_discrete_log.o $(OBJ)/main.o 
HDRS = $(INC)/factorization.h $(INC)/prime_generator.h $(INC)/miller_rabin.h $(INC)/generator.h $(INC)/crt.h $(INC)/bsgs.h $(INC)/pohlig_hellman.h $(INC)/naive_discrete_log.h
CFLAGS = -Wall -c -I$(INC) 

EXE = $(BIN)/tp1.exe

run: $(EXE)
		$(EXE) 

$(BIN)/tp1.exe: $(OBJS)
	$(CC) -o $(BIN)/tp1.exe $(OBJS) $(LIBS)

$(OBJ)/factorization.o: $(HDRS) $(SRC)/factorization.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/factorization.o $(SRC)/factorization.cpp

$(OBJ)/prime_generator.o: $(HDRS) $(SRC)/prime_generator.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/prime_generator.o $(SRC)/prime_generator.cpp

$(OBJ)/crt.o: $(HDRS) $(SRC)/crt.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/crt.o $(SRC)/crt.cpp

$(OBJ)/miller_rabin.o: $(HDRS) $(SRC)/miller_rabin.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/miller_rabin.o $(SRC)/miller_rabin.cpp

$(OBJ)/generator.o: $(HDRS) $(SRC)/generator.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/generator.o $(SRC)/generator.cpp

$(OBJ)/naive_discrete_log.o: $(HDRS) $(SRC)/naive_discrete_log.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/naive_discrete_log.o $(SRC)/naive_discrete_log.cpp

$(OBJ)/bsgs.o: $(HDRS) $(SRC)/bsgs.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/bsgs.o $(SRC)/bsgs.cpp

$(OBJ)/pohlig_hellman.o: $(HDRS) $(SRC)/pohlig_hellman.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/pohlig_hellman.o $(SRC)/pohlig_hellman.cpp

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out *grind*