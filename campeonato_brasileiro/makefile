CC = gcc
CFLAGS = -Wall

IDIR = ../campeonato_brasileiro/include
ODIR = ../campeonato_brasileiro/src
OBJDIR = objects
BINDIR = bin

SRC = $(wildcard $(ODIR)/*.c)
OBJ = $(patsubst $(ODIR)/%.c, $(OBJDIR)/%.o, $(SRC))

all: binfolder objfolder bin/main
	@ echo "Type 'make run' to run code"

bin/main: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

binfolder:
	@ echo "Creating bin directory..."
	mkdir $(BINDIR)

objfolder:
	@ echo "Creating obj directory..."
	mkdir $(OBJDIR)

$(OBJDIR)/main.o: $(ODIR)/main.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(ODIR)/%.c $(IDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean run

clean:
	del $(BINDIR)\* $(OBJDIR)\*
	rmdir $(BINDIR) $(OBJDIR)

run:
	$(BINDIR)/main