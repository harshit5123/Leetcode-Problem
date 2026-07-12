class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(),nums.end());
        vector<int>pref(n,0);
        pref[0]=nums[0];
        for (int i=1;i<n;i++){
            pref[i]=nums[i]+pref[i-1];
        }
        vector<int> ans;
        for (int i = 0; i < m; i++) {
            int sum=queries[i];
            int ind=upper_bound(pref.begin(),pref.end(),sum)-pref.begin();
            ans.push_back(ind);
        }
        return ans;
    }
};