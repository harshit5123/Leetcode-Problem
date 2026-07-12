class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for (int i = 0; i < m; i++) {
            long long sum = queries[i];
            long long querysum = 0;
            int cnt = 0;

            for (int j = 0; j < n; j++) {
                if (querysum + nums[j] <= sum) {
                    querysum += nums[j];
                    cnt += 1;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};