#include <stdio.h>
#include <stdlib.h>
#include "rlc.h"
#include "utils.h"

void init_qtable(QLearning* ql) {
    init_random_seeds();
    for (int i = 0; i < ql->state_size; i++) {
        for ( int j = 0; j < ql->action_size; j++) {
            ql->qtable[i][j] = get_random_float();
        }
    }
}

QLearning* ql_create(State state, Action actions, double alpha, double gamma, double epsilon) {
    // TODO
}

void ql_update(QLearning *ql, State state, Action action, double reward, State next_state) {
    // TODO
}

int ql_get_action(QLearning *ql, State state) {
    // TODO
}

void ql_free(QLearning *ql) {
    // TODO
}

