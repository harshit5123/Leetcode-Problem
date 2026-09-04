class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        int leftsum=0;
        int index=-1;
        for(int i=0;i<n;i++){
            int rightsum=total-leftsum-nums[i];
            if(leftsum==rightsum){
             index=i;
             break;
            }
            leftsum+=nums[i];
        }
        return index;
    }
};