class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        long long ans=0;
        // find culprit index;
        //min index
        // max index
        int culind=-1;
        int minind=-1;
        int maxind=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==minK) minind=i;
            if(nums[i]==maxK) maxind=i;
            if(nums[i]<minK || nums[i]>maxK) {
                culind=i;
            }
            long long smaller=min(minind,maxind);
            long long temp=smaller-culind;
            if(temp<=0) ans+=0;
            else ans+=temp;
        }
        return ans;
    }
};