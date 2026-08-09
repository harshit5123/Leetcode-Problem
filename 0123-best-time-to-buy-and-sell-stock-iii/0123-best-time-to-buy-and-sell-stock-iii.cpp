class Solution {
public:
    int f(int i, int buy, int cap,
          vector<int>& prices,
          vector<vector<vector<int>>>& dp) {

        // No transactions remaining
        if (cap == 0)
            return 0;

        // No days remaining
        if (i == prices.size())
            return 0;

        // Already calculated
        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        int profit = 0;

        if (buy) {

            // Buy
            int take = -prices[i] +
                       f(i + 1, 0, cap, prices, dp);

            // Don't buy
            int notTake =
                       f(i + 1, 1, cap, prices, dp);

            profit = max(take, notTake);
        }
        else {

            // Sell
            int sell = prices[i] +
                       f(i + 1, 1, cap - 1, prices, dp);

            // Don't sell
            int notSell =
                       f(i + 1, 0, cap, prices, dp);

            profit = max(sell, notSell);
        }

        return dp[i][buy][cap] = profit;
    }

    int maxProfit(vector<int>& prices) {

        int n = prices.size();
        int cap = 2;

        vector<vector<vector<int>>> dp(
            n + 1,
            vector<vector<int>>(2, vector<int>(3, -1))
        );

        return f(0, 1, cap, prices, dp);
    }
};