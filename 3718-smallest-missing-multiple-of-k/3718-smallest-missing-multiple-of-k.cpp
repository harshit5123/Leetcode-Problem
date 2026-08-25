class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
    int n=nums.size();
    unordered_map<int,int>mpp;
    for(int i=0;i<n;i++){
        mpp[nums[i]]=1;
    }
    int ans=0;
    for(int i=1;i<=101;i++){
        int num=k*i;
        if(mpp.find(num)==mpp.end()){
            ans=num;
            break;
        }
    }
    return ans;
    }
};