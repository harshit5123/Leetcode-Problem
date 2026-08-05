class Solution {
public:
    int f(int ind, vector<int>& arr, int diff, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (diff == 0 && arr[0] == 0)
                return 2;
            if (diff == 0 || diff == arr[0])
                return 1;
            return 0;
        }
        if (dp[ind][diff] != -1)
            return dp[ind][diff];
        int nottake = f(ind - 1, arr, diff, dp);
        int take = 0;
        if (arr[ind] <= diff)
            take = f(ind - 1, arr, diff - arr[ind], dp);
        return dp[ind][diff] = take + nottake;
    }
    int countPartitions(vector<int>& arr, int diff) {
        int n = arr.size();

        int total = 0;
        for (int x : arr)
            total += x;

        if (total - diff < 0)
            return 0;

        if ((total - diff) % 2)
            return 0;

        int target = (total - diff) / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(arr.size() - 1, arr, target, dp);
    }
    // same ques as count partitions of striver dp series 18 problem
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums, target);
    }
};