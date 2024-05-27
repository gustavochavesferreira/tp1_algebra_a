CC = g++
LIBS = -lm -lgmp
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/factorization.o $(OBJ)/miller_rabin.o $(OBJ)/generator.o $(OBJ)/powmod.o $(OBJ)/discrete_log.o $(OBJ)/main.o 
HDRS = $(INC)/factorization.h $(INC)/miller_rabin.h $(INC)/generator.h $(INC)/powmod.h $(INC)/discrete_log.h
CFLAGS = -Wall -c -I$(INC) 

EXE = $(BIN)/tp1.exe

run: $(EXE)
		$(EXE) 

tests: $(EXE)
	$(EXE) 1234567890123456789012345678901234568123
# 101
	$(EXE) 1234567890123456789012345678901234567889999920
# 197

test3: $(EXE)
	$(EXE) -d < 1399893231659162290225488582844000507360739523965724322028894458428263999898448734134121959642347774293805468812408356373767778163752959999999999999999999999860
# 1001


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

$(OBJ)/discrete_log.o: $(HDRS) $(SRC)/discrete_log.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/discrete_log.o $(SRC)/discrete_log.cpp

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp
	
clean:
	rm -f $(EXE) $(OBJS) gmon.out *grind*