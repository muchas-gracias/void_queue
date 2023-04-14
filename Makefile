CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Wwrite-strings
CFLAGS += -Wstack-usage=1024 -Wfloat-equal -Waggregate-return -Winline

.PHONY: all clean

all: linked

clean:
	rm -f *.o linked

linked_main.o: linked_main.c linked.h
	$(CC) $(CFLAGS) -c linked_main.c -o linked_main.o

linked.o: linked.c linked.h
	$(CC) $(CFLAGS) -c linked.c -o linked.o

linked: linked_main.o linked.o
	$(CC) $(CFLAGS) linked_main.o linked.o -o linked
