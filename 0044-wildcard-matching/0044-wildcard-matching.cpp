class Solution {
public:
    bool f(int i, int j, string &s, string &p,
           vector<vector<int>>& dp) {

        // Both exhausted and 1 index
        if (i < 0 && j < 0)
            return true;

        // Pattern exhausted but string remains
        if (j < 0 && i >= 0)
            return false;

        // String exhausted
        if (i < 0 && j >= 0) {
            for (int jj = 0; jj <= j; jj++) {
                if (p[jj] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // Character matches OR pattern has '?'
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = f(i - 1, j - 1, s, p, dp);
        }

        // '*' can:
        // 1. Match current character -> i-1, j
        // 2. Match empty sequence     -> i, j-1
        if (p[j] == '*') {
            return dp[i][j] =
                f(i - 1, j, s, p, dp) ||
                f(i, j - 1, s, p, dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(n - 1, m - 1, s, p, dp);
    }
};