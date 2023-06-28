# NMK_Solver

An m,n,k-game is an abstract board game in which two players take turns in placing a stone of their color on an **n-by-m** board, the winner being the player who first gets **k** stones of their own color in a row, horizontally, vertically, or diagonally.

NMK_Solver is program that accepts 3 commands followed by imput of values n, m, k, number of player that is supposed to make a move (either 1 or 2) and board made from numbers 0 (empty cell), 1 (firts player pawn), 2 (second player pown).

The main purpuse of the programm is using implemented minimax algorithm to evaluate the state of game and predict its outcome assuming best possible moves are made by each player. Additionally algorithm is optimalized using techniques like for example Alpha-Beta pruning.

Description of possible commands:

# 1. GEN_ALL_POS_MOV
<p>This command firstly returns number of possible moves for a player and secondly generates all posible boards after each move. <br>

Example: <br>
input:

![img1](https://github.com/Krzy-Doma/NMK_Solver/blob/main/screens/all_possible_move_1.png) <br>
output:

![img2](https://github.com/Krzy-Doma/NMK_Solver/blob/main/screens/all_possible_move_2.png) <br> </p>

# 2. GEN_ALL_POS_MOV_CUT_IF_GAME_OVER
<p>This command makes program look for a first winning move. It firstly returns number of possible moves (output 1 ususaly means it found winning move) and secondly generates either board after winning move or all posible boards after each move. <br>

Example when winning move is found: <br>
input:

![img3](https://github.com/Krzy-Doma/NMK_Solver/blob/main/screens/cut_game_over_1.png) <br>
output:

![img4](https://github.com/Krzy-Doma/NMK_Solver/blob/main/screens/cut_game_over_2.png) <br>

Example when winning move is not found: <br>
input:

![img5](https://github.com/Krzy-Doma/NMK_Solver/blob/main/screens/cut_game_over_3.png) <br>
output:

![img6](https://github.com/Krzy-Doma/NMK_Solver/blob/main/screens/cut_game_over_4.png) <br></p>

# 3. SOLVE_GAME_STATE
<p>This is the main command of the program. It is using minimax algorithm to evaluate which player is going to win or if there is a tie. It returns string with information that either one of the players (should) win the game or if there is a tie.

Example when there is a winner: <br>

input:  

![solve_game_state_1](https://github.com/Krzy-Doma/NMK_Solver/blob/main/screens/solve_game_state_1.png) <br>

output:

![solve_game_state_2](https://github.com/Krzy-Doma/NMK_Solver/blob/main/screens/solve_game_state_2.png) <br>

Example when there is a tie: <br>

input:  

![solve_game_state_3](https://github.com/Krzy-Doma/NMK_Solver/blob/main/screens/solve_game_state_3.png) <br>

output:

![solve_game_state_4](https://github.com/Krzy-Doma/NMK_Solver/blob/main/screens/solve_game_state_4.png) <br>


</p>
