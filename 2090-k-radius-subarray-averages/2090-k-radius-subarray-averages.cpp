class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> result(n,-1);
        int i=k;
        int left=0;
        int right=2*k;
        long long windowsum=0;
        if(n<2*k+1) return result;
        for(int i=left;i<=right;i++){
               windowsum+=nums[i];
        }
        int count=2*k+1;
        result[i]=windowsum/count;
        i++;
        right++;
        while(right<n){
            int out_elem=nums[left];
            int in_elem=nums[right];
            windowsum=windowsum+in_elem-out_elem;
            result[i]=windowsum/count;
            i++;
            right++;
            left++;
        }
        return result;
    }
};