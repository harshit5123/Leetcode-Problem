class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n=nums.size();
        long long xr=0;
        for(int i=0;i<n;i++){
            xr=xr^nums[i];
        }
        int b1=0,b2=0;
        int rightmost= xr & -xr;
        for(int i=0;i<n;i++){
            if(nums[i]& rightmost){
                b1=b1^nums[i];
            }
            else{
                b2=b2^nums[i];
            }
        }
        return {b1, b2};
    }
};