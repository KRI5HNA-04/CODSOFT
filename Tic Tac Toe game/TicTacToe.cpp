#include <iostream>
using namespace std;

char square[10] = {'0','1','2','3','4','5','6','7','8','9'};

int checkwin();
void board();

int main() {
    int player = 1, choice;
    char mark;
    int i;
    char playAgain;

    do {
        board();
        player = (player % 2) ? 1 : 2;
        cout << "Player " << player << ", enter a number: ";
        cin >> choice;
        mark = (player == 1) ? 'X' : 'O';

        if (choice >= 1 && choice <= 9 && square[choice] == '0' + choice) {
            square[choice] = mark;
        } else {
            cout << "Invalid move ";
            player--;
            cin.ignore();
            cin.get();
        }
        i = checkwin();
        player++;
    } while (i == -1);

    board();
    if (i == 1)
        cout << "==>\aPlayer " << --player << " wins!";
    else
        cout << "==>\aGame is a draw";

    cout << "\nDo you want to play again? (Y/N): ";
    cin >> playAgain;

    if (playAgain == 'Y' || playAgain == 'y') {
        // Reset the board and play again
        for (int j = 1; j < 10; j++) {
            square[j] = '0' + j;
        }
        main(); // Restart the game
    }

    cin.ignore();
    cin.get();
    return 0;
}

int checkwin() {
    for (int line = 1; line <= 7; line += 3) {
        if (square[line] == square[line + 1] && square[line + 1] == square[line + 2])
            return 1;
    }
    for (int col = 1; col <= 3; col++) {
        if (square[col] == square[col + 3] && square[col + 3] == square[col + 6])
            return 1;
    }
    if (square[1] == square[5] && square[5] == square[9])
        return 1;
    if (square[3] == square[5] && square[5] == square[7])
        return 1;
    if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' &&
        square[7] != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    return -1;
}

void board() {
    system("cls");
    cout << "\n\n\tTic Tac Toe\n\n";
    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;
    cout << "_____|_____|_____" << endl;
    cout << "     |     |     " << endl;
    cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;
    cout << "     |     |     " << endl << endl;
}
