#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "rlc.h"
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

void println(const char* format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    printf("\n");
}

/**
 * @brief Select the RL algorithm and return based on the created object.
 */
void* select_rl_algorithm() {
    int algorithm = 0;
    char input[10];

    println("---RL Algorithms---");
    println("-------------------------");
 
    println("1. Q-Learning");
    println("2. Deep-Q Learning Network (DQN)");
    println("3. Proximal Policy Optimization (PPO)");

    printf("Choose the RL algorithm: ");
    algorithm = atoi(fgets(input, sizeof(input), stdin));

    while(algorithm < 1 || algorithm > MAX_ALGORITHMS) {
        println("Selected algorithm is not supported!");
        printf("Choose the RL algorithm: ");
        algorithm = atoi(fgets(input, sizeof(input), stdin));
    }

    println("Selected algorithm: %d", algorithm);

    switch(algorithm) {
        case 1: {
            State state;
            state.state = 0;
            Action actions;
            actions.action = 0;
            
            QLearning *ql = ql_create(state, actions, 0.1, 0.7, 0.49);
            return ql;
        }
        default:
            println("Selected algorithm is not supported!");
            return NULL;
    }
}