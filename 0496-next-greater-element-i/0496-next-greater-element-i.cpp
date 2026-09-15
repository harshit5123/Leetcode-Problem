class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            bool find=false;
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]) find=true;
                if(find && nums1[i] <nums2[j]){
                    ans[i]=nums2[j];
                    break;
                }
            }
            if(ans[i]==0) ans[i]=-1;
        }
        return ans;
    }
};