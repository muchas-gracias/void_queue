CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Wwrite-strings
CFLAGS += -Wstack-usage=1024 -Wfloat-equal -Waggregate-return -Winline

.PHONY: all clean format

all: queue

clean:
	rm -f *.o queue

format:
	clang-format -i queue.c queue.h queue_main.c

queue_main.o: queue_main.c queue.h
	$(CC) $(CFLAGS) -c queue_main.c -o queue_main.o

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c -o queue.o

queue: queue_main.o queue.o
	$(CC) $(CFLAGS) queue_main.o queue.o -o queue

queue_main.o queue.o: queue.h

# Run 'format' target before building the code
all: format queue

# Run 'format' target before cleaning the code
clean: format
	rm -f *.o queue
