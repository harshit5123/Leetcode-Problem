class Solution {
public:
    int ans = 0;

    bool isSafe(int row, int col, vector<string>& board, int n) {

        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Upper-left diagonal
        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0;
             i--, j--) {

            if (board[i][j] == 'Q')
                return false;
        }

        // Upper-right diagonal
        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n;
             i--, j++) {

            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int row, int n, vector<string>& board) {

        // All queens placed
        if (row == n) {
            ans++;
            return;
        }

        for (int col = 0; col < n; col++) {

            if (isSafe(row, col, board, n)) {

                // Choose
                board[row][col] = 'Q';

                // Explore
                solve(row + 1, n, board);

                // Undo
                board[row][col] = '.';
            }
        }
    }

    int totalNQueens(int n) {

        vector<string> board(n, string(n, '.'));

        solve(0, n, board);

        return ans;
    }
};