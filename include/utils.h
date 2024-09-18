#ifndef UTILS_H
#define UTILS_H

#define MAX_ALGORITHMS 3

#include "rlc.h"

void init_random_seeds();
int get_random_int(int min, int max);
float get_random_float();
void println(const char* format, ...);
RLAlgorithm* select_rl_algorithm();

#endif // UTILS_H