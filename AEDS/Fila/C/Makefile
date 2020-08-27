CC=gcc
CFLAGS=-W -Wall
LDFLAGS=
EXEC=filas.exe
DEPS= tipos.h erros.h

all: $(EXEC)

$(EXEC): filaLE.o filaV.o main.c
	$(CC) filaLE.o filaV.o main.c -o $(EXEC) $(LDFLAGS)

filaLE.o: $(DEPS) fila.h filaLE.h filaLE.c
	$(CC) -c filaLE.c -o filaLE.o $(CFLAGS)
filaV.o: $(DEPS) fila.h filaV.h filaV.c
	$(CC) -c filaV.c -o filaV.o $(CFLAGS)

clean:
	del /Q *.o

mrproper: clean
	del /Q $(EXEC)