class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return 1;
        if(n == 2) return 2;

        int maxi = INT_MIN;
        int maxiIND = -1;

        int mini = INT_MAX;
        int miniIND = -1;

        for(int i = 0; i < n; i++) {

            if(nums[i] > maxi) {
                maxi = nums[i];
                maxiIND = i;
            }

            if(nums[i] < mini) {
                mini = nums[i];
                miniIND = i;
            }
        }

        // Cost if we delete both from left
        int left = max(maxiIND, miniIND) + 1;

        // Cost if we delete both from right
        int right = n - min(maxiIND, miniIND);

        // Cost if we delete max from left and min from right
        int both1 = maxiIND + 1 + (n - miniIND);

        // Cost if we delete min from left and max from right
        int both2 = miniIND + 1 + (n - maxiIND);

        return min({left, right, both1, both2});
    }
};