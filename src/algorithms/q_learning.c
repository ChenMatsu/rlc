#include "rlc.h"
#include <stdio.h>
#include <stdlib.h>


struct QLearning {
    // TODO
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
