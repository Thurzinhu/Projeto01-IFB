CFLAGS = -Wall
CC = gcc

IDIR = ../acertou_miseravi/include
ODIR = ../acertou_miseravi/src

SRC = $(wildcard $(ODIR)/*.c)
OBJ = $(patsubst $(ODIR)/%.c,%.o,$(SRC))

main: $(OBJ)
	@ echo "Compilando arquivos..."
	$(CC) $(CFLAGS) $^ -o $@

$(ODIR)/%.o: %.c $(IDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm main $(OBJ)