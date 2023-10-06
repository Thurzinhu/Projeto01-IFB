#include "../include/read.h"
#include "../include/interpreter.h"

int main()
{
    int rows;
    char instructions[MAX_ROWS][MAX_CHAR];
    
    // lendo instruções
    read(instructions, &rows);

    // interpretando instruções
    interpret(instructions, rows);

    return 0;
}