 all:
	gcc -Wall -O3 -o factorial_resursion.exe factorial_resursion.c

# this is a comment
SRC=factorial_resursion.c
OBJ=$(SRC:.c=.o) # replaces the .c from SRC with .o
EXE=factorial_resursion.exe

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
