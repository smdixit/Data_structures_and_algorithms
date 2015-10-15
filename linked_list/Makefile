#Makefile for linked list files.

.PHONY : all clean

SRC=linked_list.c linked_list_test.c
OBJ=$(SRC:.c=.o) # replaces the .c from SRC with .o
EXE=linked_list

CC=gcc
CFLAGS=-c -Wall -O3
LDFLAGS=
RM=rm

all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	-$(RM) $(OBJ) $(EXE)
