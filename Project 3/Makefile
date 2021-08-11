#Makefile
CC= gcc
CFLAGS= -g -c
LFLAGS= -o
OBJECTS=GrammatikopoulosKolotouros.o spnoise.o flipvert.o fliphor.o rotate90right.o rotate90left.o rotate180.o 
TARGET=GrammatikopoulosKolotouros

default: GrammatikopoulosKolotouros

GrammatikopoulosKolotouros:  GrammatikopoulosKolotouros.o spnoise.o flipvert.o fliphor.o rotate90right.o rotate90left.o rotate180.o
	$(CC) $(LFLAGS) GrammatikopoulosKolotouros GrammatikopoulosKolotouros.o spnoise.o flipvert.o fliphor.o rotate90right.o rotate90left.o rotate180.o

GrammatikopoulosKolotouros.o: header.h GrammatikopoulosKolotouros.c
	$(CC) $(CFLAGS) GrammatikopoulosKolotouros.c

spnoise.o: spnoise.c
	$(CC) $(CFLAGS) spnoise.c
flipvert.o: flipvert.c
	$(CC) $(CFLAGS) flipvert.c
fliphor.o: fliphor.c
	$(CC) $(CFLAGS) fliphor.c
rotate90right.o: rotate90right.c
	$(CC) $(CFLAGS) rotate90right.c
rotate90left.o: rotate90left.c
	$(CC) $(CFLAGS) rotate90left.c
rotate180.o: rotate180.c
	$(CC) $(CFLAGS) rotate180.c

clean: 
	rm -f $(OBJECTS) $(TARGET) 





