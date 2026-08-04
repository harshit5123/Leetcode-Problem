class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
        vector<bool> ans(101,false);
        int mini=nums[0];
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
            ans[nums[i]]=true;
            }
        for(int i=mini ;i<=maxi;i++){
            if(!ans[i]){
                res.push_back(i);
            }
        }
        return res;

    }
};