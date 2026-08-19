class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int jum=0;
        int l=0;int r=0;
        while(r<n-1){
            int farthest=0;
            for(int ind=l ;ind<=r ;ind++){
                farthest=max(farthest,ind+nums[ind]);
            }
            l=r+1;
            r=farthest;
            jum=jum+1;
        }
        return jum;
    }
};