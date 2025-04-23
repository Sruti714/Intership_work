#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentPlayer = 'X';

void displayBoard() {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool isWinner() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || 
            (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || 
        (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        return true;
    }
    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void playMove(int move) {
    int row = (move - 1) / 3;
    int col = (move - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentPlayer;
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    } else {
        cout << "Invalid move! Try again.\n";
    }
}

int main() {
    int move;
    cout << "Welcome to Tic-Tac-Toe!\n";
    displayBoard();

    while (true) {
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        if (move < 1 || move > 9) {
            cout << "Invalid input. Please choose a number between 1 and 9.\n";
            continue;
        }

        playMove(move);
        displayBoard();

        if (isWinner()) {
            cout << "Player " << ((currentPlayer == 'X') ? 'O' : 'X') << " wins!\n";
            break;
        }
        if (isDraw()) {
            cout << "It's a draw!\n";
            break;
        }
    }

    return 0;
}
