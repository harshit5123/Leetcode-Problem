class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        int n=nums.size();
        long long ans=0;
        sort(nums.begin(),nums.end(),greater<int>());
        int i=0;
        while(k>0){
            if(mul>0){
                ans+=1ll*(nums[i]*1ll*mul);
                i++;
                mul--;
                k--;
            }
            else{
                ans+=(long long)nums[i];
                i++;
                k--;
            }
         }
        return ans;
    }
};