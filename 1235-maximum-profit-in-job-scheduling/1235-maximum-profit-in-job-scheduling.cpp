class Solution {
public:
    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit) {

        int n = profit.size();

        // Create jobs
        vector<tuple<int, int, int>> jobs;

        for(int i = 0; i < n; i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }

        // Sort according to start time
        sort(jobs.begin(), jobs.end());

        // dp[i] = maximum profit from job i onwards
        vector<int> dp(n + 1, 0);

        // Fill from right to left
        for(int ind = n - 1; ind >= 0; ind--) {

            int start = get<0>(jobs[ind]);
            int end = get<1>(jobs[ind]);
            int money = get<2>(jobs[ind]);

            // Don't take current job
            int notTake = dp[ind + 1];

            // Find next compatible job
            int next = ind + 1;

            while(next < n && get<0>(jobs[next]) < end) {
                next++;
            }

            // Take current job
            int take = money + dp[next];

            dp[ind] = max(take, notTake);
        }

        return dp[0];
    }
};