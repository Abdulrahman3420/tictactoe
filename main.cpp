/*
#include <iostream>

using namespace std;

char game_spaces[3][3]

        {
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

    //Introduction
    cout << "\nWelcome to Tic Tac Toe! -------" << endl;

    // Code to get player names
    cout << "\nPlease Enter the name for First Player: " << endl;
    cin >> first_person;
    cout << "Your name is: " << first_person << "! " << endl;

    cout << "\nPlease Enter the name for Second Player: " << endl;
    cin >> second_person;
    cout << "Your name is: " << second_person << "! " << endl;

    // Player Rules
    cout << "\nPlayer Rules: "
        << first_person << " will go first." << endl;

    cout << second_person << " will go second." << endl;

    //Game Structure

    cout << "/\nLets Begin! \n" << endl;

    cout << "\n     |       |   " << endl;
    cout << " " << game_spaces[0][0] << "   |   " << game_spaces[0][1] << "   |   " << game_spaces[0][2] << endl;
    cout << "-------------------------" << endl;
    cout << "     |       |   " << endl;
    cout << "  " << game_spaces[1][0] << "  |   " << game_spaces[1][1] << "   |   " << game_spaces[1][2] << endl;
    cout << "-------------------------" << endl;
    cout << "     |       |   " << endl;
    cout << " " << game_spaces[2][0] << "   |   " << game_spaces[2][1] << "   |   " << game_spaces[2][2] << endl;
    cout << "     |       |   " << endl;

}

void gamefunction1() {
    int digit;
    if (symbol == 'X') {
        cout << first_person << " Please Choose your Number: ";
        cin >> digit;
    } else {
        cout << second_person << " Please Choose your Number: ";
        cin >> digit;
    }

    // If Condition:

    if (digit == 1) {
        row = 0;
        column = 0;
    }

    else if (digit == 2) {
        row = 0;
        column = 1;
    }

    else if (digit == 3) {
        row = 0;
        column = 2;
    }

    else if (digit == 4) {
        row = 1;
        column = 0;
    }
    else if (digit == 5) {
        row = 1;
        column = 1;
    }
    else if (digit == 6) {
        row = 1;
        column = 2;
    }
    else if (digit == 7) {
        row = 2;
        column = 0;
    }
    else  if (digit == 8) {
        row = 2;
        column = 1;
    }

    else if (digit == 9) {
        row = 2;
        column = 2;
    } else {
        cout << " -_- :-( ;-) Your Chosen Space is Invalid -_- :-( ;-)" << endl;
    }

    if (symbol == 'X' && game_spaces[row][column] != 'X' && game_spaces[row][column] != '0')
    {
        game_spaces[row][column] = 'X';
        symbol = 'O';
    }

    else if (symbol == '0' && game_spaces[row][column] != 'X' && game_spaces[row][column] != '0')
    {
        game_spaces[row][column] = '0';
        symbol = 'X';
    }

    else
    {
        cout << "There is no empty space!" << endl;
    }

};

bool gamefunction2() {
    for (int i = 0; i < 3; i++) {
        if (game_spaces[i][0] == game_spaces[i][1] && game_spaces[i][0] == game_spaces[i][2] || 
			game_spaces[0][i] == game_spaces[1][i] && game_spaces[0][i] == game_spaces[2][i])
            #draw1=true;
            return true;
    		}

    if (game_spaces[0][0] == game_spaces[1][1] && game_spaces[0][0] == game_spaces[2][2] || game_spaces[0][2] == game_spaces[1][1] && game_spaces[0][2] == game_spaces[2][0])
        draw2=true;
        //return true;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (game_spaces[i][j] != 'X' && game_spaces[i][j] != 'O') {
                draw3=false
                //return false;
            }
        }
    }

    if (draw1=true and draw2=true and draw2=false)
            draw=true;
            return draw;
     else
         draw=false

     end if;
    return draw;
    //return false;  // Return false to indicate the game is not over
}
int main()
{

    cout<<"VAlue for Gamefunction is "<<gamefunction2()<<endl;

    while (!gamefunction2()) {
        draw = false;
        gameFunction0();
        gamefunction1();
        if (symbol == 'X') {
            symbol = 'O';
        } else {
            symbol = 'X';
        }
    }

    if (symbol == 'X' && !draw) {
        cout << first_person << " Wins!" << endl;
    } else if (symbol == 'O' && !draw) {
        cout << second_person << " Wins!" << endl;
    } else {
        cout << "It's a Tie!" << endl;
    }

    return 0;
}*/


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
