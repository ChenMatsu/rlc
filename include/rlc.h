#ifndef RLC_H
#define RLC_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    // TODO
} State;

typedef struct {
    // TODO
} Action;

typedef struct {
    // TODO
} Environment;

// Q-Learning
typedef struct QLearning {
    State state;
    Action actions;
    double alpha;
    double gamma;
    double epsilon;
    double **qtable;
    int state_size;
    int action_size;
} QLearning;
QLearning *ql_create(State state, Action actions, double alpha, double gamma, double epsilon);
void ql_update(QLearning *ql, State state, Action action, double reward, State next_state);
int ql_get_action(QLearning *ql, State state);
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
