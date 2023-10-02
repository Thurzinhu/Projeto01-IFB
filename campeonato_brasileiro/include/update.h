#ifndef UPDATE_H
#define UPDATE_H

#include "../include/read.h"

void get_points(int gols[], int pontos[]);
void update_status(char equipes[][MAX_CHAR], time times[], int gols[], int pontos[], int num_times);

#endif