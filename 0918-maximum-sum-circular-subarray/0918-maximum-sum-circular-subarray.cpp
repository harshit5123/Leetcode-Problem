class Solution {
public:
    int minKadane(vector<int>& nums) {
    int sum = nums[0];
    int mini = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        sum = min(nums[i], sum + nums[i]);
        mini = min(mini, sum);
    }

    return mini;
}
    int maxKadane(vector<int>& nums) {
    int sum = nums[0];
    int maxi = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        sum = max(nums[i], sum + nums[i]);
        maxi = max(maxi, sum);
    }

    return maxi;
}
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int maxkad=maxKadane(nums);
        int minkad=minKadane(nums);
        int csum=total-minkad;
        if(maxkad>0) return max(maxkad,csum);
        return maxkad;

    }
};