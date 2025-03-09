#include <iostream>

#define N 9

bool isValid(int board[N][N], int row, int col, int num) {

    for (int i = 0; i < N; i++) {
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow + i][startCol + j] == num)
                return false;
        }
    }
    return true;
}

bool solveSudoku(int board[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (isValid(board, row, col, num)) {
                        board[row][col] = num;

                        if (solveSudoku(board))
                            return true;

                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    std::cin >> T;

    for (int testCase = 1; testCase <= T; testCase++) {
        int board[N][N];

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                std::cin >> board[i][j];

        std::cout << "#" << testCase << ":\n";

        if (solveSudoku(board)) {
            printBoard(board);
        } else {
            std::cout << "No solution!\n";
        }
    }

    return 0;
}

