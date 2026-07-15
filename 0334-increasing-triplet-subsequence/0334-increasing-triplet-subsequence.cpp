class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int num1=nums[0];
        int num2=INT_MAX;
        for (int i=1;i<n;i++){
            if (nums[i]<=num1) num1=nums[i];

            else if (nums[i]<=num2) num2=nums[i];

            else if (nums[i]>num2) return true;
        }
        return false;
    }
};