#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <stdbool.h>

#define BOARD_SIZE 3
#define MAX_NUM_ACTIONS 9

typedef enum {
    EMPTY = 0,
    PLAYER_X = 1,
    PLAYER_O = -1,
} CellState;

typedef struct {
    bool done;
    CellState board[BOARD_SIZE][BOARD_SIZE];
    CellState current_player;
} TicTacToeState;

typedef struct {
    TicTacToeState state;
} TicTacToeEnv;

TicTacToeEnv* tic_tac_toe_init();

void tic_tac_toe_reset(TicTacToeEnv* env);

void tic_tac_toe_step_human(TicTacToeEnv* env, int action);
double tic_tac_toe_step_rl(TicTacToeEnv* env, int action, TicTacToeState* next_state, bool* done);

TicTacToeState tic_tac_toe_get_state(TicTacToeEnv* env);

bool tic_tac_toe_is_valid_action(TicTacToeEnv* env, int action);

void tic_tac_toe_render(TicTacToeEnv* env);

void tic_tac_toe_free(TicTacToeEnv* env);

#endif // TIC_TAC_TOE_H
