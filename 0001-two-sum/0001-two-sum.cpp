class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            int num=nums[i];
            int ans=target-num;
            if(mpp.find(ans)!=mpp.end()) {
                return {mpp[ans],i};
            }
            mpp[num]=i;
        }
        return {};
    }
};