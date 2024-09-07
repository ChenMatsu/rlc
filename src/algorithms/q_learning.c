#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rlc.h"
#include "utils.h"

void init_qtable(QLearning* ql);

/**
 * @brief Create a Q-Learning object.
 * @param 
 *    state: State object.
 *    action: Action object.
 *    gamma: Discount factor.
 */
QLearning* ql_create(State state, Action action, double alpha, double gamma, double epsilon) {
    QLearning *ql = malloc(sizeof(QLearning));
    if(ql == NULL) {
        println("Failed to allocate memory for QLearning!");
        return NULL;
    }

    ql->alpha = alpha;
    ql->gamma = gamma;
    ql->epsilon = epsilon;

    init_qtable(ql);
    return ql;
}

/**
 * @brief Update the Q-Table based on the state, action, reward, and next state.
 * @param
 *    reward: Reward value.
 *    next_state: Next state.
 */
void ql_update(QLearning *ql, State state_obj, Action action_obj, double reward, State next_state_obj) {
    double max_q_next = ql->q_table[next_state_obj.state][0];
    
    for (int a = 1; a < ql->action_size; a++) {
        if (ql->q_table[next_state_obj.state][a] > max_q_next) {
            max_q_next = ql->q_table[next_state_obj.state][a];
        }
    }

    double current_q = ql->q_table[state_obj.state][action_obj.action];
    ql->q_table[state_obj.state][action_obj.action] = current_q + ql->alpha * (reward + ql->gamma * max_q_next - current_q);
}

/**
 * @brief Get the action based on the state using "ε-greedy" method.
 */
int ql_get_action(QLearning *ql, State state_obj) {
    if(get_random_float() < ql->epsilon) {
        // Exploration: Select a random action.
        return get_random_int(0, ql->action_size);
    } else {
        // Exploitation: Select the best action. (with highest Q-value)
        int best_action = 0;
        double max_q = ql->q_table[state_obj.state][0];
        for(int a = 1; a < ql->action_size; a++) {
            if(ql->q_table[state_obj.state][a] > max_q) {
                max_q = ql->q_table[state_obj.state][a];
                best_action = a;
            }
        }
        return best_action;
    }
}

void ql_reset(QLearning *ql) {
    init_qtable(ql);
}

void ql_free(QLearning *ql) {
    free(ql);
}

/**
 * @brief Initialize the Q-Table with random values.
 */
void init_qtable(QLearning* ql) {
    init_random_seeds();

    for (int i = 0; i < ql->state_size; i++) {
        for (int j = 0; j < ql->action_size; j++) {
            ql->q_table[i][j] = get_random_float();
        }
    }
}
