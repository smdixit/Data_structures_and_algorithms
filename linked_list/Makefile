 all:
	gcc -Wall -O3 -o linked_list.exe linked_list_test.c linked_list.c

# this is a comment
SRC=linked_list.c linked_list_test.c
OBJ=$(SRC:.c=.o) # replaces the .c from SRC with .o
EXE=linked_list.exe

CC=gcc
CFLAGS=-Wall -O3
LDFLAGS=-mwindows
RM=rm

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

.PHONY : all
all: $(EXE)

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $@

.PHONY : clean
clean:
	-$(RM) $(OBJ) core
