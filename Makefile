CC = gcc
CFLAGS = -I. -g -std=c99 -Wall

all: pnn

pnn: pnn.c
	$(CC) -o $@ $^ $(CFLAGS) -lm

clean:
	rm -f pnn
