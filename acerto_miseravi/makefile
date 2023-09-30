CFLAGS = -Wall
CC = gcc

IDIR = ../acerto_miseravi/include
ODIR = ../acerto_miseravi/src
BINDIR = bin
OBJDIR = objects

# all source code files in src directory
SRC = $(wildcard $(ODIR)/*.c)

# substituting all src/*.c to objects/*.o  
# same as OBJ = $(SRC:$(ODIR).c=$(OBJDIR).o)
OBJ = $(patsubst $(ODIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# main target 
all: binfolder objfolder $(BINDIR)/main
	@ echo "Type 'make run' to run code"

# to create main we need all object files
$(BINDIR)/main: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

binfolder:
	@ echo "Creating bin directory..."
	mkdir -p $(BINDIR)

objfolder:
	@ echo "Creating obj directory..."
	mkdir -p $(OBJDIR)

# object files
$(OBJDIR)/main.o: $(ODIR)/main.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(ODIR)/%.c $(IDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean run

# removing all files in created directories and then deleting those directories
clean:
	rm -f $(BINDIR)/* $(OBJDIR)/*
	rmdir $(BINDIR) $(OBJDIR)

# running code
run:
	$(BINDIR)/main
