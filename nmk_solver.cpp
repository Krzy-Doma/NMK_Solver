#include <iostream>
#include <string>

using namespace std;

const int MIN = -1000;
const int MAX = 1000;

char** generateTable(int n, int m) {
    char** tab = new char* [n];
    for (int i = 0; i < n; i++)
        tab[i] = new char[m];

    return tab;
}

void writeTable(char** tab, int n, int m) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> tab[i][j];
    }
}

void freeTable(char** tab, int n) {
    for (int i = 0; i < n; i++)
        delete[] tab[i];

    delete[] tab;
}

int evaluateBoard(char** tab, int n, int m, int k) {

    //horizontal
    for (int i = 0; i < n; i++) {
        int tmp1 = 0;
        int tmp2 = 0;
        for (int j = 0; j < m; j++) {
            if (tab[i][j] == '1')
                tmp1++;
            else
                tmp1 = 0;

            if (tab[i][j] == '2')
                tmp2++;
            else
                tmp2 = 0;

            if (tmp1 >= k)
                return 1;
            else if (tmp2 >= k)
                return -1;
        }
    }

    //vertical
    for (int j = 0; j < m; j++) {
        int tmp1 = 0;
        int tmp2 = 0;
        for (int i = 0; i < n; i++) {
            if (tab[i][j] == '1')
                tmp1++;
            else
                tmp1 = 0;

            if (tab[i][j] == '2')
                tmp2++;
            else
                tmp2 = 0;

            if (tmp1 >= k)
                return 1;
            else if (tmp2 >= k)
                return -1;
        }
    }

    //diagonal rl
    for (int i = 0; i < n - k + 1; i++) {
        for (int j = 0; j < m - k + 1; j++) {
            int tmp1 = 0;
            int tmp2 = 0;
            for (int l = 0; l < k; l++) {
                if (tab[i + l][j + l] == '1')
                    tmp1++;
                else
                    tmp1 = 0;

                if (tab[i + l][j + l] == '2')
                    tmp2++;
                else
                    tmp2 = 0;

                if (tmp1 >= k)
                    return 1;
                else if (tmp2 >= k)
                    return -1;
            }
        }
    }

    //diagonal lr
    for (int i = 0; i < n - k + 1; i++) {
        for (int j = m - 1; j >= k - 1; j--) {
            int tmp1 = 0;
            int tmp2 = 0;
            for (int l = 0; l < k; l++) {
                if (tab[i + l][j - l] == '1')
                    tmp1++;
                else
                    tmp1 = 0;

                if (tab[i + l][j - l] == '2')
                    tmp2++;
                else
                    tmp2 = 0;

                if (tmp1 >= k)
                    return 1;
                else if (tmp2 >= k)
                    return -1;
            }
        }
    }

    return 0;
}

void printTable(char** tab, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << tab[i][j] << ' ';
        cout << '\n';
    }
}

int countPossibleMoves(char** tab, int n, int m) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tab[i][j] == '0') {
                count++;
            }
        }
    }
    return count;
}

void generateAllPossibleMoves(char** tab, int n, int m, char player) {
    char** tmp = tab;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tmp[i][j] == '0') {
                tmp[i][j] = player;
                printTable(tmp, n, m);
                tmp[i][j] = '0';
            }
        }
    }
}

void generateAllPossibleWins(char** tab, int n, int m, int k, char player) {
    char** tmp = tab;
    int wincount = 0;
    int notwincount = 0;
    int playerint = player - '0';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tmp[i][j] == '0') {
                notwincount++;
                tmp[i][j] = player;
                if (evaluateBoard(tmp, n, m, k) != 0) {
                    wincount = 1;
                    cout << wincount << '\n';
                    printTable(tmp, n, m);
                    return;
                }
                tmp[i][j] = '0';
            }
        }
    }
    cout << notwincount << '\n';
    generateAllPossibleMoves(tab, n, m, player);


}

int minimax(char** tab, int n, int m, int k, int depth, bool isMax, int alpha, int beta) {
    int score = evaluateBoard(tab, n, m, k);
    char** tmp = tab;

    if (score == 1)
        return score;
    else if (score == -1)
        return score;
    else if (score == 0 && countPossibleMoves(tab, n, m) == 0)
        return score;

    if (isMax) {
        int best = MIN;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tmp[i][j] == '0') {
                    tmp[i][j] = '1';
                    int score = minimax(tmp, n, m, k, depth + 1, !isMax, alpha, beta);
                    if (score > best)
                        best = score;
                    
                    tmp[i][j] = '0';
                    if (best > alpha)
                        alpha = best;
                    if (beta <= alpha)
                        break;
                }
            }
        }

        return best;
    }

    else {
        int best = MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (tmp[i][j] == '0') {
                    tmp[i][j] = '2';
                    int score = minimax(tmp, n, m, k, depth + 1, !isMax, alpha, beta);
                    if (best > score)
                        best = score;
                    
                    tmp[i][j] = '0';
                    if (beta > best)
                        beta = best;
                    if (beta <= alpha)
                        break;
                }
            }
        }

        return best;
    }
}

void allSolutions(int n, int m, int k, char player) {

    char** tab = generateTable(n, m);
    writeTable(tab, n, m);
    int p = evaluateBoard(tab, n, m, k);
    if (p != 0) {
        cout << "0\n";
        freeTable(tab, n);
        return;
    }

    cout << countPossibleMoves(tab, n, m) << '\n';
    generateAllPossibleMoves(tab, n, m, player);
    freeTable(tab, n);
}

void cutIfOverSolutions(int n, int m, int k, int player) {
    char** tab = generateTable(n, m);
    writeTable(tab, n, m);
    int a = evaluateBoard(tab, n, m, k);
    if (a != 0) {
        cout << "0\n";
        freeTable(tab, n);
        return;
    }

    generateAllPossibleWins(tab, n, m, k, player);
    freeTable(tab, n);
}

void solveGameStateSolutions(int n, int m, int k, char player) {
    char** tab = generateTable(n, m);
    writeTable(tab, n, m);
    int a = evaluateBoard(tab, n, m, k);
    if (a == 1) {
        cout << "FIRST_PLAYER_WINS\n";
        freeTable(tab, n);
        return;
    }
    else if (a == -1) {
        cout << "SECOND_PLAYER_WINS\n";
        freeTable(tab, n);
        return;
    }
    else if (a == 0 && countPossibleMoves(tab, n, m) == 0) {
        cout << "BOTH_PLAYERS_TIE\n";
        freeTable(tab, n);
        return;
    }
    else {
        bool isMax;
        if (player == '1')
            isMax = true;
        else
            isMax = false;

        int eval = minimax(tab, n, m, k, 0, isMax, MIN, MAX);
        if (eval == 1) {
            cout << "FIRST_PLAYER_WINS\n";
        }
        else if (eval == -1) {
            cout << "SECOND_PLAYER_WINS\n";
        }
        else if (eval == 0) {
            cout << "BOTH_PLAYERS_TIE\n";
        }
        freeTable(tab, n);
    }



    
}


int main() {
    string cmd;
    int m, n, k;
    char player;


    while (true) {
        cin >> cmd;

        if (feof(stdin) != 0) {
            break;
        }

        cin >> n >> m >> k >> player;
        
        if (cmd == "GEN_ALL_POS_MOV")
            allSolutions(n, m, k, player);

        else if (cmd == "GEN_ALL_POS_MOV_CUT_IF_GAME_OVER")
            cutIfOverSolutions(n, m, k, player);

        else if (cmd == "SOLVE_GAME_STATE")
            solveGameStateSolutions(n, m, k, player);


    }


}
