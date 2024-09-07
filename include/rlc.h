#ifndef RLC_H
#define RLC_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STATES 100
#define MAX_ACTIONS 100

// @Issue: the states and actions structure might need to be changed.
typedef struct {
    int state;
} State;

typedef struct {
    int action;
} Action;

typedef struct {
    int num_states;
    int num_actions;
} Environment;

// Q-Learning
typedef struct QLearning {
    State states;
    Action actions;
    int state_size;
    int action_size;
    double alpha;
    double gamma;
    double epsilon;
    double **q_table;
} QLearning;
QLearning *ql_create(State state, Action actions, double alpha, double gamma, double epsilon);
void ql_update(QLearning *ql, State state, Action action, double reward, State next_state);
int ql_get_action(QLearning *ql, State state);
void ql_reset(QLearning *ql);
void ql_free(QLearning *ql);

// DQN
typedef struct DQN DQN;
DQN *dqn_create(State state, Action actions, double alpha, double gamma, double epsilon);
void dqn_update(DQN *dqn, State state, Action action, double reward, State next_state);
int dqn_get_action(DQN *dqn, State state);
void dqn_free(DQN *dqn);

// PPO
typedef struct PPO PPO;
PPO *ppo_create(State state, Action actions, double alpha, double gamma, double epsilon);
void ppo_update(PPO *ppo, State state, Action action, double reward, State next_state);
int ppo_get_action(PPO *ppo, State state);
void ppo_free(PPO *ppo);

#endif // RLC_H
