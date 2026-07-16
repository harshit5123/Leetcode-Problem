class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int cnt0 = 0;
        int i = 0;
        int maxi = INT_MIN;
        for (int j = 0; j < n; j++) {
            if (nums[j] == 0)
                cnt0++;
            while (cnt0 > 1) {
                if (nums[i] == 0) cnt0--;
                i++;
                    
            }
            maxi = max(maxi, j - i);
        }
        return maxi;
    }
};