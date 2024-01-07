

#include <iostream>
#include <algorithm>

using namespace std;

char game_spaces[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
};

int row;
int column;
char symbol = 'X';
bool draw = false;

string player_name;

void gameFunction0() {
    cout << "\nWelcome to Tic Tac Toe! -------" << endl;

    cout << "\nPlease Enter your name: " << endl;
    cin >> player_name;
    cout << "Your name is: " << player_name << "! " << endl;

    cout << "\nLet's Begin!\n" << endl;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << game_spaces[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "-----------\n";
    }
}

bool isMovesLeft() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game_spaces[i][j] != 'X' && game_spaces[i][j] != 'O') {
                return true; // There are still available moves
            }
        }
    }
    return false; // No available moves
}

int evaluateBoard() {
    for (int i = 0; i < 3; i++) {
        if (game_spaces[i][0] == game_spaces[i][1] && game_spaces[i][0] == game_spaces[i][2]) {
            if (game_spaces[i][0] == 'X') return -1; // Player wins
            else if (game_spaces[i][0] == 'O') return 1; // AI wins
        }
        if (game_spaces[0][i] == game_spaces[1][i] && game_spaces[0][i] == game_spaces[2][i]) {
            if (game_spaces[0][i] == 'X') return -1; // Player wins
            else if (game_spaces[0][i] == 'O') return 1; // AI wins
        }
    }

    if (game_spaces[0][0] == game_spaces[1][1] && game_spaces[0][0] == game_spaces[2][2]) {
        if (game_spaces[0][0] == 'X') return -1; // Player wins
        else if (game_spaces[0][0] == 'O') return 1; // AI wins
    }
    if (game_spaces[0][2] == game_spaces[1][1] && game_spaces[0][2] == game_spaces[2][0]) {
        if (game_spaces[0][2] == 'X') return -1; // Player wins
        else if (game_spaces[0][2] == 'O') return 1; // AI wins
    }

    return 0; // No winner
}

int minimax(bool isMaximizer) {
    int score = evaluateBoard();

    if (score != 0) {
        return score;
    }

    if (!isMovesLeft()) {
        return 0;
    }

    int bestScore = isMaximizer ? -1000 : 1000;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game_spaces[i][j] != 'X' && game_spaces[i][j] != 'O') {
                char originalValue = game_spaces[i][j];
                game_spaces[i][j] = isMaximizer ? 'O' : 'X';

                int currentScore = minimax(!isMaximizer);
                if (isMaximizer) {
                    bestScore = max(bestScore, currentScore);
                } else {
                    bestScore = min(bestScore, currentScore);
                }

                game_spaces[i][j] = originalValue; // Undo the move
            }
        }
    }

    return bestScore;
}

pair<int, pair<int, int>> findBestMove() {
    int bestVal = -1000;
    pair<int, pair<int, int>> bestMove;
    bestMove.first = -1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game_spaces[i][j] != 'X' && game_spaces[i][j] != 'O') {
                char originalValue = game_spaces[i][j];
                game_spaces[i][j] = 'O';

                int moveVal = minimax(false);

                game_spaces[i][j] = originalValue; // Undo the move

                if (moveVal > bestVal) {
                    bestMove.first = i;
                    bestMove.second = make_pair(i, j);
                    bestVal = moveVal;
                }
            }
        }
    }

    return bestMove;
}

void gamefunction1() {
    int digit;
    if (symbol == 'X') {
        cout << player_name << ", Please Choose your Number: ";
        cin >> digit;
    }

    if (digit >= 1 && digit <= 9) {
        row = (digit - 1) / 3;
        column = (digit - 1) % 3;

        if (game_spaces[row][column] != 'X' && game_spaces[row][column] != 'O') {
            game_spaces[row][column] = symbol;
            symbol = (symbol == 'X') ? 'O' : 'X';
        } else {
            cout << "This space is already taken. Try again." << endl;
            gamefunction1();
        }
    } else {
        cout << "Invalid input. Please choose a number between 1 and 9." << endl;
        gamefunction1();
    }
}

bool gamefunction2() {
    for (int i = 0; i < 3; i++) {
        if (game_spaces[i][0] == game_spaces[i][1] && game_spaces[i][0] == game_spaces[i][2] ||
            game_spaces[0][i] == game_spaces[1][i] && game_spaces[0][i] == game_spaces[2][i]) {
            return true;
        }
    }

    if (game_spaces[0][0] == game_spaces[1][1] && game_spaces[0][0] == game_spaces[2][2] ||
        game_spaces[0][2] == game_spaces[1][1] && game_spaces[0][2] == game_spaces[2][0]) {
        return true;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game_spaces[i][j] != 'X' && game_spaces[i][j] != 'O') {
                return false;
            }
        }
    }

    draw = true;
    return true;
}

int main() {
    gameFunction0();

    while (!gamefunction2()) {
        if (symbol == 'X') {
            gamefunction1();
        } else {
            pair<int, pair<int, int>> bestMove = findBestMove();
            row = bestMove.second.first;
            column = bestMove.second.second;
            game_spaces[row][column] = 'O'; // AI's turn
            symbol = 'X'; // Switch back to player's turn
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << " " << game_spaces[i][j] << " ";
                if (j < 2) cout << "|";
            }
            cout << endl;
            if (i < 2) cout << "-----------\n";
        }
    }

    if (draw) {
        cout << "The game ended in a draw!" << endl;
    } else if (symbol == 'O') { // Checking if the AI won
        cout << "AI Wins!" << endl;
    } else {
        cout << player_name << " Wins!" << endl; // If AI didn't win, player wins
    }

    return 0;

}


