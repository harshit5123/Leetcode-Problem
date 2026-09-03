class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n=nums1.size();
        int smallest=INT_MAX;
        for(int i=0;i<n;i++){
                smallest=min(smallest,nums1[i]);
            }
        if(smallest%2==1) return true;
        for(int i=0;i<n;i++){
            if(nums1[i]%2==1) return false;
        }
    return true;
    }
};