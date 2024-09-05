#ifndef UTILS_H
#define UTILS_H

void init_random_seeds();

int get_random_int(int min, int max);

float get_random_float();

void println(const char* format, ...);

#endif // UTILS_H