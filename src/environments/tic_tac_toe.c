#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "utils.h"
#include "tic_tac_toe.h"

static bool check_win(TicTacToeEnv* env);
static bool check_draw(TicTacToeEnv* env);

TicTacToeEnv* tic_tac_toe_init() {
    TicTacToeEnv* env = (TicTacToeEnv*)malloc(sizeof(TicTacToeEnv));
    tic_tac_toe_reset(env);
    return env;
}

void tic_tac_toe_reset(TicTacToeEnv* env) {
    memset(env->state.board, EMPTY, sizeof(env->state.board));
    env->state.current_player = PLAYER_X; // Default player
}

void tic_tac_toe_render(TicTacToeEnv* env) {
    println("---Current board---");
    char symbols[] = {'O', '.', 'X'};

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", symbols[env->state.board[i][j] + 1]);
        }
        printf("\n");
    }
}

void tic_tac_toe_free(TicTacToeEnv* env) {
    free(env);
}

void tic_tac_toe_step_human(TicTacToeEnv* env, int move) {
    int row = move / BOARD_SIZE;
    int col = move % BOARD_SIZE;

    printf("Your move = %d, row = %d, col = %d\n", move, row, col);

    if (!tic_tac_toe_is_valid_action(env, move)) {
        printf("The field is already taken! Try again. \n"); 
        return;
    }
    
    printf("Player %c takes move %d\n", env->state.current_player == PLAYER_X ? 'X' : 'O', move);
    env->state.board[row][col] = env->state.current_player;

    if (check_win(env)) {
        env->state.done = true;
        println("Player %c wins!", env->state.current_player == PLAYER_X ? 'X' : 'O');
        tic_tac_toe_render(env);
        return;
    }

    if (check_draw(env)) {
        env->state.done = true;
        println("It's a draw!");
        tic_tac_toe_render(env);
        return;
    }
    
    env->state.current_player = -env->state.current_player; // Switch player
    return;
}

/**
 * @brief 
 *      RL powered step function for Tic-Tac-Toe. This should provide with multiple algorithms.
 * 
 * @param
 *      env: the environment
 *      action: the action to be taken between 0~8 (inclusive) from upper-left to lower-right
 *      next_state: the next state after taking the action (RL Applied)
 *      done: the flag to indicate whether the game is over
 */
double tic_tac_toe_step_rl(TicTacToeEnv* env, int action, TicTacToeState* next_state, bool* done) {
    int row = action / BOARD_SIZE;
    int col = action % BOARD_SIZE;

    if (!tic_tac_toe_is_valid_action(env, action)) {
        *done = true;
        *next_state = env->state;
        return -10.0; // Penalty for invalid action/move
    }

    env->state.board[row][col] = env->state.current_player;
    *next_state = env->state;

    if (check_win(env)) {
        *done = true;
        return 1.0;
    }

    if (check_draw(env)) {
        *done = true;
        return 0.5;
    }

    env->state.current_player = -env->state.current_player;
    *done = false;
    return 0.0;
}

TicTacToeState tic_tac_toe_get_state(TicTacToeEnv* env) {
    return env->state;
}

bool tic_tac_toe_is_valid_action(TicTacToeEnv* env, int action) {
    int row = action / BOARD_SIZE;
    int col = action % BOARD_SIZE;
    return env->state.board[row][col] == EMPTY;
}


static bool check_win(TicTacToeEnv* env) {
    CellState player = env->state.current_player;

    // Check rows and columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if((env->state.board[i][0] == player &&
            env->state.board[i][1] == player &&
            env->state.board[i][2] == player) ||
            (env->state.board[0][i] == player &&
            env->state.board[1][i] == player &&
            env->state.board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if((env->state.board[0][0] == player &&
        env->state.board[1][1] == player &&
        env->state.board[2][2] == player) ||
        (env->state.board[0][2] == player &&
        env->state.board[1][1] == player &&
        env->state.board[2][0] == player)) {
        return true;
    }

    return false;
}

static bool check_draw(TicTacToeEnv* env) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (env->state.board[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}