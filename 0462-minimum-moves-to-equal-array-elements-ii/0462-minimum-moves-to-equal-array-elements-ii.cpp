class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int idx=n/2;
        int minmoves=0;
        for(int i=0;i<n;i++){
            minmoves+=abs(nums[i]-nums[idx]);
        }
    return minmoves;
    }
};