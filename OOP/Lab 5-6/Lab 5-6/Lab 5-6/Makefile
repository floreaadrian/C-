CC=gcc
CFLAGS=-W -Wall
LDFLAGS=
SRC= $(wildcard *.cpp)
OBJ= $(SRC:.c=.o)

all: myexec

myexec: $(OBJ)
    @$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
    @$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean

