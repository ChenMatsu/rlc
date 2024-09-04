#include "tic_tac_toe.h"
#include <stdlib.h>
#include <string.h>

TicTacToeEnv* tic_tac_toe_init() {
    TicTacToeEnv* env = (TicTacToeEnv*)malloc(sizeof(TicTacToeEnv));
    tic_tac_toe_reset(env);
    return env;
}

void tic_tac_toe_reset(TicTacToeEnv* env) {
    memset(env->state.board, EMPTY, sizeof(env->state.board));
    env->state.current_player = PLAYER_X;
}

double tic_tac_toe_step(TicTacToeEnv* env, int action, TicTacToeState* next_state, bool* done) {
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

void tic_tac_toe_render(TicTacToeEnv* env, char* buffer) {
    int pos = 0;
    char symbols[] = {'.', 'X', 'O'};

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            buffer[pos++] = symbols[env->state.board[i][j] + 1];
            buffer[pos++] = ' ';
        }
        buffer[pos++] = '\n';
    }
    buffer[pos] = '\0';
}

void tic_tac_toe_free(TicTacToeEnv* env) {
    free(env);
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
            if (env->state[i][j] == EMPTY) {
                return false;
            }
        }
    }
    return true;
}