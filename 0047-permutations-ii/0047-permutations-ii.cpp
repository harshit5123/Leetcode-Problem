class Solution {
public:
    int n;
    set<vector<int>> st;
    void solve(int index,vector<int>&nums){
       n=nums.size();
       if(index==n){
           st.insert(nums);
           return;
       }
       for(int i=index;i<n;i++){
           swap(nums[i],nums[index]);
           solve(index+1,nums);
           swap(nums[i],nums[index]);
       }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        solve(0,nums);
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};