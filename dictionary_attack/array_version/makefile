CC = gcc
CFLAGS = -Wall -g
LDLIBS = -lcrypto

IDIR = ./include
ODIR = ./src
OBJDIR = objects
BINDIR = bin
INPUTDIR = ./input
TESTPATH = /home/arthur/Projetos-IFB-2023/test_project_03/input

SRC = $(wildcard $(ODIR)/*.c)
OBJ = $(patsubst $(ODIR)/%.c, $(OBJDIR)/%.o, $(SRC))

all: objfolder binfolder $(BINDIR)/main

$(BINDIR)/main: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

objfolder:
	mkdir -p $(OBJDIR)

binfolder:
	mkdir -p $(BINDIR)

$(OBJDIR)/%.o: $(ODIR)/%.c $(IDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/main.o: $(ODIR)/main.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean run

clean:
	rm -rf $(OBJDIR) $(BINDIR) report.txt

run:
	$(BINDIR)/main $(INPUTDIR)/users.txt $(INPUTDIR)/passwords.txt ./report.txt