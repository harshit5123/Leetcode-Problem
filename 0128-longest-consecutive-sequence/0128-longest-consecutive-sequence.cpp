class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int maxi=0;
        int cnt=0;
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]==1 ){
                cnt++;
                maxi=max(maxi,cnt);
            }
            else if(nums[i]==nums[i-1]) {
                continue;
            }
            else {
                cnt=0;
            }
        }
        return maxi+1;
    }
};