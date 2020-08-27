CC=gcc
CFLAGS=-W -Wall
LDFLAGS=
EXEC=listas.exe
DEPS= tipos.h erros.h

all: $(EXEC)

$(EXEC): listaED.o listaES.o listaORD.o main.c
	$(CC) listaED.o listaES.o listaORD.o main.c -o $(EXEC) $(LDFLAGS)

listaED.o: $(DEPS) lista.h listaED.h listaED.c
	$(CC) -c listaED.c -o listaED.o $(CFLAGS)
listaES.o: $(DEPS) lista.h listaES.h listaES.c
	$(CC) -c listaES.c -o listaES.o $(CFLAGS)
listaORD.o: $(DEPS) lista.h listaORD.h listaORD.c
	$(CC) -c listaORD.c -o listaORD.o $(CFLAGS)

clean:
	del /Q *.o

mrproper: clean
	del /Q $(EXEC)