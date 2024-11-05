// N-Queens Problem
#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col) {
    int n = board.size();
    for (int i = 0; i < col; i++) if (board[row][i]) return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) if (board[i][j]) return false;
    for (int i = row, j = col; j >= 0 && i < n; i++, j--) if (board[i][j]) return false;
    return true;
}

bool solveNQUtil(vector<vector<int>>& board, int col) {
    int n = board.size();
    if (col >= n) return true;
    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQUtil(board, col + 1)) return true;
            board[i][col] = 0;
        }
    }
    return false;
}

void solveNQ(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0));
    if (!solveNQUtil(board, 0)) cout << "Solution does not exist";
    for (auto row : board) { for (auto cell : row) cout << (cell ? "Q " : ". "); cout << endl; }
}

int main() { solveNQ(4); return 0; }
