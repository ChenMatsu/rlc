#ifndef UTILS_H
#define UTILS_H

void init_random();

int get_random_int(int min, int max);

float get_random_float();

void init_qtable(QLearning* q);

#endif // UTILS_H