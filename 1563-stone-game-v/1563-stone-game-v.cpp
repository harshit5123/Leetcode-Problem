class Solution {
public:
    int solve(int l, int r, vector<int>& prefix,vector<vector<int>>&dp) {
        if (l == r)
            return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        int score = 0;
        for (int k = l; k < r; k++) {
            int leftSum = prefix[k + 1] - prefix[l];
            int rightSum = prefix[r + 1] - prefix[k + 1];
            // left side check karo
            if (leftSum < rightSum) {
                score = max(score,leftSum + solve(l, k, prefix,dp));
            }
            // right side 
            else if (rightSum < leftSum) {
                score = max(score,rightSum + solve(k + 1, r, prefix,dp));
            }
            // agar equal ho to
            else {
                score = max(score,max(leftSum + solve(l, k, prefix,dp),rightSum + solve(k + 1, r, prefix,dp)));
            }
        }

        return dp[l][r]=score;
    }

    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> prefix(n + 1, 0);
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stoneValue[i];
        }
    return solve(0, n - 1, prefix,dp);
    }
};