#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "tic_tac_toe.h"

void tic_tac_toe_normal(TicTacToeEnv* env);

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
        /**
         * TODO: Implement the AI vs Human and AI vs AI mode with multiple algorithmsr supported.
         */
        case 2: {
            // TODO AI vs Human
            println("AI vs Human mode is not supported yet!");
            break;
        }
        case 3: {
            // TODO AI vs AI
            println("AI vs AI mode is not supported yet!");
            break;
        }
        default: {
            printf("Invalid mode!\n");
            break;
        }
    }
    return 0;
}

void tic_tac_toe_normal(TicTacToeEnv* env) {
    int action = -1;
     while(env->state.done == false) {
        tic_tac_toe_render(env);
        
        printf("Enter your action(0~8): ");
        scanf("%d", &action);

        while(action < 0 || action > 8) {
            if(action < 0 || action > 8) {
                println("Invalid action!");
                printf("Enter your action(0~8): ");
                scanf("%d", &action);
            }
        }
        tic_tac_toe_step_human(env, action);
    }
}