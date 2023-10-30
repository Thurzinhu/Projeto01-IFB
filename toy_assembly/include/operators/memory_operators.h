#ifndef MEMORY_OPERATORS_H
#define MEMORY_OPERATORS_H

void load(int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count);
void store(int registers[], int memory[], int rx, int ry, int rz, int integer, int *is_true, int register_count);

#endif