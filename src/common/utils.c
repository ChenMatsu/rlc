#include "utils.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

void init_random() {
    srand(time(NULL));
}

int get_random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

float get_random_float() {
    return (float)rand() / (float)RAND_MAX;
}

void init_qtable(QLearning* ql) {
    init_random();
    for (int i = 0; i < ql->state_size; i++) {
        for ( int j = 0; j < ql->action_size; j++) {
            ql->qtable[i][j] = get_random_float();
        }
    }
}

