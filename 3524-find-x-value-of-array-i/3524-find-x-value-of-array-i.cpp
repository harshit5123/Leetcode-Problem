class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<long long> result(k, 0);
        vector<long long> prev(k, 0);

        for (int i = 0; i < n; i++) {
            vector<long long> currcount(k, 0);

            int currem = nums[i] % k;

            // Subarray containing only nums[i]
            currcount[currem]++;

            // Extend all previous subarrays
            for (int oldrem = 0; oldrem < k; oldrem++) {
                int newrem = (1LL * oldrem * nums[i]) % k;

                currcount[newrem] += prev[oldrem];
            }

            prev = move(currcount);

            // Add all subarrays ending at i
            for (int x = 0; x < k; x++) {
                result[x] += prev[x];
            }
        }

        return result;
    }
};