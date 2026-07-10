class Solution {
public:
     // 1. 23+6%6= rem=5 hi hoga
     //1.check karo ki remainder map me present hai ya nhi agar present hai or uska size 2 se bada hai to true return karo.
     //2. agar map me present nhi hai to mpp[rem]=i
     //3. 0 ko alreadty mpp[0]=-1 karke store rakho beacause he boundary case hi..
     
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int sum = 0;
        mpp[0] = -1;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int rem = sum % k;
            if (mpp.find(rem) != mpp.end()) {
                if (i - mpp[rem] >= 2)
                    return true;
            } else {
                mpp[rem] = i;
            }
        }
        return false;
    }
};