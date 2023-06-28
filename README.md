# NMK_Solver

An m,n,k-game is an abstract board game in which two players take turns in placing a stone of their color on an **n-by-m** board, the winner being the player who first gets **k** stones of their own color in a row, horizontally, vertically, or diagonally.

NMK_Solver is program that accepts 3 commands followed by imput of values n, m, k, number of player that is supposed to make a move (either 1 or 2) and board made from numbers 0 (empty cell), 1 (firts player pawn), 2 (second player pown).

Description of possible commands:

# 1. GEN_ALL_POS_MOV
This command firstly returns number of possible moves for a player and secondly generates all posible boards after each move.

Example:
input:

![img1](https://github.com/Krzy-Doma/NMK_Solver/blob/main/screens/all_possible_move_1.png)(`<br>`)
output:

![img2](https://github.com/Krzy-Doma/NMK_Solver/blob/main/screens/all_possible_move_2.png)

# 2. GEN_ALL_POS_MOV_CUT_IF_GAME_OVER

# 3. SOLVE_GAME_STATE
