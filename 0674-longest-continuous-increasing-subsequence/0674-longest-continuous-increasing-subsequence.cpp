class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int j=1;
        int maxcnt=1;
        int cnt=1;
        while(j<n){
            if(nums[j]>nums[i]) {
                cnt++;
                j++;
                i++;
                maxcnt=max(maxcnt,cnt);
            }
            else{

                i=j;
                j=j+1;
                cnt=1;
            }
        }
        return maxcnt;
    }
};