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
RLAlgorithm* select_rl_algorithm() {
    RLAlgorithm *rl = malloc(sizeof(RLAlgorithm));

    println("---RL Algorithms---");
    println("-------------------------");
    println("1. Q-Learning");
    println("2. Deep-Q Learning Network (DQN)");
    println("3. Proximal Policy Optimization (PPO)");

    printf("Choose the RL algorithm: ");
    int algorithm = 0;
    char input[10];
    algorithm = atoi(fgets(input, sizeof(input), stdin));

    while(algorithm < 1 || algorithm > MAX_ALGORITHMS) {
        println("Selected algorithm is not supported!");
        printf("Choose the RL algorithm: ");
        algorithm = atoi(fgets(input, sizeof(input), stdin));
    }

    switch(algorithm) {
        case 1: {
            char buffer[100];
            double alpha, gamma, epsilon;

            printf("Enter the α value for Q-Learning method (0~1): ");
            alpha = strtod(fgets(buffer, sizeof(buffer), stdin), NULL);

            while(alpha < 0 || alpha > 1) {
                println("Invalid α value!");
                printf("Enter the α value for Q-Learning method (0~1): ");
                alpha = atoi(fgets(buffer, sizeof(buffer), stdin));
            }

            printf("Enter the γ value for Q-Learning method (0~1): ");
            gamma =  strtod(fgets(buffer, sizeof(buffer), stdin), NULL);

            while(gamma < 0 || gamma > 1) {
                println("Invalid γ value!");
                printf("Enter the γ value for Q-Learning method (0~1): ");
                gamma = atoi(fgets(buffer, sizeof(buffer), stdin));
            }

            printf("Enter the ε value for ε-greedy method (0~1): ");
            epsilon = strtod(fgets(buffer, sizeof(buffer), stdin), NULL);

            while(epsilon < 0 || epsilon > 1) {
                println("Invalid ε value!");
                printf("Enter the ε value for ε-greedy method (0~1): ");
                epsilon = atoi(fgets(buffer, sizeof(buffer), stdin));
            }
            
            // @Issue: How to correctly pass states and actions in general way?
            Action actions;
            actions.action[0] = 0;
            State states;
            states.state[0][0] = 0;
            QLearning *ql = ql_create(states, actions, alpha, gamma, epsilon);

            rl->type = Q_LEARNING;
            rl->algorithm.ql = *ql;

            println("rl->algorithm: %p", rl->algorithm);

            println("You have selected Q-Learning algorithm!");
            println("α: %.2f, γ: %.2f, ε: %.2f", alpha, gamma, epsilon);
            return rl;
        }
        case 2: {
            break;
        }
        case 3: {
            break;
        }
        default:
            println("Selected algorithm is not supported!");
            return NULL;
    }
}