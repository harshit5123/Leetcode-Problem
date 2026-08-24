class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        vector<int>copy=nums;
        sort(copy.begin(),copy.end());
        int i=1;
        int j=n-1;
        while(i<nums.size()){
            nums[i]=copy[j];
            j--;
            i+=2;
            }
        i=0;
        while(i<n){
           nums[i]=copy[j];
           i+=2;
           j--;
        }
    }
};