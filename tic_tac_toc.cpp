#include <iostream>

using namespace std;

char board[3][3];
char currentMarker;
int currentPlayer;

void initializeBoard() {
    char startChar = '1';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = startChar++;
        }
    }
}

void drawBoard() {
    cout << "Current Tic-Tac-Toe Board:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "--|---|--" << endl;
    }
    cout << endl;
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    } else {
        return false;
    }
}

int checkWinner() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return currentPlayer;
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return currentPlayer;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return currentPlayer;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return currentPlayer;
    }

    return 0; // No winner yet
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void swapPlayerAndMarker() {
    if (currentMarker == 'X') {
        currentMarker = 'O';
    } else {
        currentMarker = 'X';
    }

    if (currentPlayer == 1) {
        currentPlayer = 2;
    } else {
        currentPlayer = 1;
    }
}

void playGame() {
    currentMarker = 'X';
    currentPlayer = 1;
    int winner = 0;
    int slot;

    initializeBoard();

    while (winner == 0 && !isBoardFull()) {
        drawBoard();
        cout << "Player " << currentPlayer << "'s turn. Enter your slot: ";
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Please try again.\n";
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot already occupied! Please try again.\n";
            continue;
        }

        winner = checkWinner();
        if (winner == 0) {
            swapPlayerAndMarker();
        }
    }

    drawBoard();

    if (winner != 0) {
        cout << "Player " << winner << " wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }
}

bool askToPlayAgain() {
    char choice;
    cout << "Do you want to play again? (y/n): ";
    cin >> choice;

    return (choice == 'y' || choice == 'Y');
}

int main() {
    do {
        playGame();
    } while (askToPlayAgain());

    cout << "Thanks for playing!" << endl;

    return 0;
}
