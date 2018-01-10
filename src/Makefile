CC=gcc
CFLAGS=-Wall
OBJ=cipher.o crack1.o main.o
TARGET=xorcipher

util : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

cipher.o: cipher.c
crack1.o: crack1.c
main.o: main.c

clean:
	rm -rf *.o
