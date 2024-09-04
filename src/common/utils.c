#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

void init_random_seeds() {
    srand(time(NULL));
}

int get_random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

float get_random_float() {
    return (float)rand() / (float)RAND_MAX;
}
