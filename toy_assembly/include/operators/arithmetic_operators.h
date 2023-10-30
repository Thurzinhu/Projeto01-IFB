#ifndef ARITHMETIC_OPERATORS_H
#define ARITHMETIC_OPERATORS_H

void add(int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count);
void sub(int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count);
void my_div(int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count);
void mul(int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count);
void mod(int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count);

#endif