#include <iostream>
#include <vector>
void displayBoard(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

bool checkWin(const std::vector<std::vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

int main() {
    std::vector<std::vector<char>> board(3, std::vector<char>(3, ' '));
    char currentPlayer = 'X';
    bool gameWon = false;

    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;

    do {
        std::cout << "Current board:" << std::endl;
        displayBoard(board);
        int row, col;
        do {
            std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            std::cin >> row >> col;
        } while (row < 1 || row > 3 || col < 1 || col > 3 || board[row - 1][col - 1] != ' ');
        board[row - 1][col - 1] = currentPlayer;
        if (checkWin(board, currentPlayer)) {
            std::cout << "Player " << currentPlayer << " wins! Congratulations!" << std::endl;
            gameWon = true;
        } else {
            bool draw = true;
            for (const auto& row : board) {
                for (char cell : row) {
                    if (cell == ' ') {
                        draw = false;
                        break;
                    }
                }
                if (!draw) {
                    break;
                }
            }
            if (draw) {
                std::cout << "It's a draw! Good game!" << std::endl;
                gameWon = true;
            } else {
                currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
            }
        }
    } while (!gameWon);

    return 0;
}
