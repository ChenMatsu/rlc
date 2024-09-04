#include "rlc.h"
#include <stdio.h>
#include <stdlib.h>

PPO* ppo_create(State state, Action actions, double alpha, double gamma, double epsilon) {
    // TODO
}

void ppo_update(PPO *ppo, State state, Action action, double reward, State next_state) {
    // TODO
}

int ppo_get_action(PPO *ppo, State state) {
    // TODO
}

void ppo_free(PPO *ppo) {
    // TODO
}