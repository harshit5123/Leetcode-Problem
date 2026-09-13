class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(auto interval:intervals){
            if(ans.empty() || ans.back()[1]<interval[0]){
                  ans.push_back(interval);
            }
            else{
                ans.back()[1]=max(interval[1],ans.back()[1]);
            }
        }
        return ans;
    }
};