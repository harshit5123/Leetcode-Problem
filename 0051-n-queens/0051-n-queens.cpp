class Solution {
public:
    bool isSafe(int row, int col, vector<string>& board, int n) {

        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1;
             i >= 0 && j >= 0;
             i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1;
             i >= 0 && j < n;
             i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int row, int n, vector<string>& board,
               vector<vector<string>>& ans) {

        // All rows filled
        if (row == n) {
            ans.push_back(board);
            return;
        }

        // Try every column in this row
        for (int col = 0; col < n; col++) {

            if (isSafe(row, col, board, n)) {

                // Choose
                board[row][col] = 'Q';

                // Explore
                solve(row + 1, n, board, ans);

                // Undo
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        solve(0, n, board, ans);

        return ans;
    }
};