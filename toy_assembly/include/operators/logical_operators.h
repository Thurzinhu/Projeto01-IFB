#ifndef LOGICAL_OPERATORS_H
#define LOGICAL_OPERATORS_H

void beq(int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count);
void blt(int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count);
void jmp(int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count);

#endif