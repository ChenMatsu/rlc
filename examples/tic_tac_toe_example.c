#include <stdio.h>
#include <stdlib.h>
#include "rlc.h"
#include "utils.h"
#include "tic_tac_toe.h"

void tic_tac_toe_normal(TicTacToeEnv* env);
void tic_tac_toe_rl(TicTacToeEnv* env);

int main() {
    println("Welcome to the Tic-Tac-Toe Game!");

    char input[10];

    int mode = 1;
    char player = 'x';
    println("---Modes---");
    println("-------------------------");
    println("1. Human vs Human");
    println("2. Human vs AI");
    println("3. AI vs AI");
    printf("Choose the mode: ");

    fgets(input, sizeof(input), stdin);
    mode = atoi(input);

    while(mode < 1 || mode > 3) {
        println("Invalid mode!");
        printf("Choose the mode: ");
        fgets(input, sizeof(input), stdin);
        mode = atoi(input);
    }

    printf("Choose the player you want X or O: ");
    fgets(input, sizeof(input), stdin);
    player = input[0];

    while(player != 'X' && player != 'O') {
        println("Invalid player!");
        printf("Choose X or O: ");
        fgets(input, sizeof(input), stdin);
        player = input[0];
    }
    
    TicTacToeEnv* env = tic_tac_toe_init();    
    env->state.current_player = (player == 'X') ? PLAYER_X : PLAYER_O;

    switch (mode) {
        case 1: {
            tic_tac_toe_normal(env);
            break;
        }
        case 2: {
            tic_tac_toe_rl(env);
            break;
        }
        // TODO AI vs AI
        case 3: {
            println("AI vs AI mode is not supported yet!");
            break;
        }
        default: {
            println("Invalid mode!");
            break;
        }
    }
    return 0;
}

void tic_tac_toe_normal(TicTacToeEnv* env) {
    int move = -1;
    while(env->state.done == false) {
        tic_tac_toe_render(env);
        
        printf("Enter your move(0~8): ");
        scanf("%d", &move);

        while(move < 0 || move > 8) {
            if(move < 0 || move > 8) {
                println("Invalid move!");
                printf("Enter your move(0~8): ");
                scanf("%d", &move);
            }
        }
        tic_tac_toe_step_human(env, move);
    }
}

void tic_tac_toe_rl(TicTacToeEnv* env) {
    RLAlgorithm* opt = (RLAlgorithm*)select_rl_algorithm();  // Select different RL algorithm to compete with AI Agent.

    int move = -1;
    while(env->state.done == false) {
        tic_tac_toe_render(env);

        if(env->state.current_player == PLAYER_X) {
            // Player's turn
            println("--- Your turn ---");
            printf("Enter your move(0~8): ");
            scanf("%d", &move);
            
            while(move < 0 || move > 8) {
                println("Invalid move!");
                printf("Enter your move(0~8): ");
                scanf("%d", &move);
            }

            tic_tac_toe_step_human(env, move);
        } else {
            // AI's turn
            println("--- Opponent's turn ---");
            // ql_get_action(opt->algorithm);
            // double reward = tic_tac_toe_step_rl(env, action, algo->ql->states, env->state.done);
            // ql_update(algo, env->state, action, reward, algo->ql->states);
            return;
        }
    }
}