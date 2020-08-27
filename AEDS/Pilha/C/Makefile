CC=gcc
CFLAGS=-W -Wall
LDFLAGS=
EXEC=pilhas.exe
DEPS= tipos.h erros.h

all: $(EXEC)

$(EXEC): pilhaLE.o pilhaV.o main.c
	$(CC) pilhaLE.o pilhaV.o main.c -o $(EXEC) $(LDFLAGS)

pilhaLE.o: $(DEPS) pilha.h pilhaLE.h pilhaLE.c
	$(CC) -c pilhaLE.c -o pilhaLE.o $(CFLAGS)
pilhaV.o: $(DEPS) pilha.h pilhaV.h pilhaV.c
	$(CC) -c pilhaV.c -o pilhaV.o $(CFLAGS)

clean:
	del /Q *.o

mrproper: clean
	del /Q $(EXEC)