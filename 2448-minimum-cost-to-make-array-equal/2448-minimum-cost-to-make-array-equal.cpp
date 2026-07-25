class Solution {
public:
    long long findcost(vector<int>& nums, vector<int>& cost, long long target) {
        long long result = 0;

        for (int i = 0; i < nums.size(); i++) {
            result += 1LL * abs(nums[i] - target) * cost[i];
        }

        return result;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {

        long long low = *min_element(nums.begin(), nums.end());
        long long high = *max_element(nums.begin(), nums.end());

        long long result = LLONG_MAX;

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            long long cost1 = findcost(nums, cost, mid);
            long long cost2 = findcost(nums, cost, mid - 1);

            result = min(result, min(cost1, cost2));

            if (cost2 > cost1)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return result;
    }
};