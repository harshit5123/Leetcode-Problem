class Solution {
public:

    int solve(vector<int>& jobDifficulty, int n, int idx, int d,
              vector<vector<int>>& dp) {

        // Only one day left
        if(d == 1) {
            int maxi = INT_MIN;

            for(int i = idx; i < n; i++) {
                maxi = max(maxi, jobDifficulty[i]);
            }

            return maxi;
        }

        if(dp[idx][d] != -1)
            return dp[idx][d];

        int maxi = INT_MIN;
        int finalres = INT_MAX;

        // Leave at least d-1 jobs for remaining days
        for(int i = idx; i <= n - d; i++) {

            maxi = max(maxi, jobDifficulty[i]);

            int result = maxi +
                solve(jobDifficulty, n, i + 1, d - 1, dp);

            finalres = min(finalres, result);
        }

        return dp[idx][d] = finalres;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {

        int n = jobDifficulty.size();

        if(n < d) return -1;

        vector<vector<int>> dp(n, vector<int>(d + 1, -1));

        return solve(jobDifficulty, n, 0, d, dp);
    }
};