class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        int subsets=1<<n;
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        for(int num=0;num<subsets;num++){
             vector<int>list;
             for(int i=0;i<n;i++){
                if(num&(1<<i)){
                    list.push_back(nums[i]);
                }
             }
             st.insert(list);
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};