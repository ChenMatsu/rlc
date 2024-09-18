#ifndef RLC_H
#define RLC_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STATES 100
#define MAX_ACTIONS 100

typedef struct QLearning QLearning;
// typedef struct DQN DQN;
// typedef struct PPO PPO;

// @Issue: the states and actions structure might need to be changed.
typedef struct {
    double state[MAX_STATES][MAX_ACTIONS];
} State;

typedef struct {
    int action[MAX_ACTIONS];
} Action;

typedef struct {
    State states;
    Action actions;
} Environment;

struct QLearning {
    State states;
    Action actions;
    int state_size;
    int action_size;
    double alpha;
    double gamma;
    double epsilon;
    double **q_table;
};

typedef enum {
    Q_LEARNING,
    DQN,
    PPO
} AlgorithmType;

typedef union {
    QLearning ql;
    // DQN dqn;
    // PPO ppo;
} AlgorithmUnion;

typedef struct {
    AlgorithmType type;
    AlgorithmUnion algorithm;
} RLAlgorithm;


// typedef struct DQN DQN;
// typedef struct PPO PPO;


QLearning *ql_create(State states, Action actions, double alpha, double gamma, double epsilon);
void ql_update(QLearning *ql, State state, Action action, double reward, State next_state);
int ql_get_action(QLearning *ql);
void ql_reset(QLearning *ql);
void ql_free(QLearning *ql);

// DQN

// RLAlgorithm *dqn_create(State state, Action actions, double alpha, double gamma, double epsilon);
// void dqn_update(DQN *dqn, State state, Action action, double reward, State next_state);
// int dqn_get_action(DQN *dqn, State state);
// void dqn_free(DQN *dqn);

// PPO

// RLAlgorithm *ppo_create(State state, Action actions, double alpha, double gamma, double epsilon);
// void ppo_update(PPO *ppo, State state, Action action, double reward, State next_state);
// int ppo_get_action(PPO *ppo, State state);
// void ppo_free(PPO *ppo);



#endif // RLC_H
