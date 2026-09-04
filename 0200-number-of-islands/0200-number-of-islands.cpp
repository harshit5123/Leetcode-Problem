class Solution {
private:
    void dfs(int r, int c, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Out of bounds or water
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == '0')
            return;

        // Mark as visited
        grid[r][c] = '0';

        // 4 directions
        dfs(r + 1, c, grid);
        dfs(r - 1, c, grid);
        dfs(r, c + 1, grid);
        dfs(r, c - 1, grid);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == '1') {
                    count++;

                    // Visit the complete island
                    dfs(i, j, grid);
                }
            }
        }

        return count;
    }
};