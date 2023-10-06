CC = gcc
CFLAGS = -Wall -I$(IDIR) -g

IDIR = ../toy_assembly/include
ODIR = ../toy_assembly/src
OBJDIR = objects
BINDIR = bin
OPRDIR = operators

SRC1 = $(wildcard $(ODIR)/*.c)
OBJ1 = $(patsubst $(ODIR)/%.c, $(OBJDIR)/%.o, $(SRC1))

SRC2 = $(wildcard $(ODIR)/$(OPRDIR)/*.c)
OBJ2 = $(patsubst $(ODIR)/$(OPRDIR)/%.c, $(OBJDIR)/%.o, $(SRC2))

OBJ := $(OBJ1) $(OBJ2)

all: binfolder objfolder bin/main
	@ echo "Type 'make run' to run code"

bin/main: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

binfolder:
	@ echo "Creating bin directory..."
	mkdir -p $(BINDIR)

objfolder:
	@ echo "Creating obj directory..."
	mkdir -p $(OBJDIR)

$(OBJDIR)/main.o: $(ODIR)/main.c 
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(ODIR)/%.c $(IDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(ODIR)/$(OPRDIR)/%.c $(IDIR)/$(OPRDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean run

clean:
	rm -f $(BINDIR)/* $(OBJDIR)/*
	rmdir $(BINDIR) $(OBJDIR)

run:
	$(BINDIR)/main