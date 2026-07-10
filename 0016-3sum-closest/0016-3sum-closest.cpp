class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closesum=nums[0]+nums[1]+nums[2];
        for (int k = 0; k < n; k++) {
            int i = k + 1;
            int j = n - 1;
            while (i < j) {
                int sum=nums[i]+nums[j]+nums[k];
                if (abs(target - sum) < abs(target - closesum)) {
                    closesum = sum;
                }
                if (sum < target)
                    i++;
                else if (sum > target)
                    j--;
                else
                    return target;
            }
        }
        return closesum;
    }
};