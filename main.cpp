TRIAL 2



/*


#include <iostream>

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

string first_person;
string second_person;

void gameFunction0() {
    cout << "\nWelcome to Tic Tac Toe! -------" << endl;

    cout << "\nPlease Enter the name for First Player: " << endl;
    cin >> first_person;
    cout << "Your name is: " << first_person << "! " << endl;

    cout << "\nPlease Enter the name for Second Player: " << endl;
    cin >> second_person;
    cout << "Your name is: " << second_person << "! " << endl;

    cout << "\nPlayer Rules: " << first_person << " will go first." << endl;
    cout << second_person << " will go second." << endl;

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

void gamefunction1() {
    int digit;
    if (symbol == 'X') {
        cout << first_person << ", Please Choose your Number: ";
        cin >> digit;
    } else {
        cout << second_person << ", Please Choose your Number: ";
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
        gamefunction1();
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
    } else if (symbol == 'X') {
        cout << second_person << " Wins!" << endl;
    } else {
        cout << first_person << " Wins!" << endl;
    }

    return 0;
}
*/

