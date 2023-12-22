CC = gcc
CFLAGS = -Wall -O3 -g

ODIR = ./src
IDIR = ./include
BINDIR = bin
OBJDIR = objects
SRC = $(wildcard $(ODIR)/*.c)
OBJ = $(patsubst $(ODIR)/%.c, $(OBJDIR)/%.o, $(SRC))

all: objfolder binfolder $(BINDIR)/main

objfolder:
	mkdir -p $(OBJDIR)

binfolder:
	mkdir -p $(BINDIR)

$(BINDIR)/main: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(ODIR)/%.c $(IDIR)/%.h
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR)/main.o: $(ODIR)/main.c
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean run

clean:
	rm -rf $(OBJDIR) $(BINDIR) output.txt

run:
	./$(BINDIR)/main ./input/report.txt output.txt