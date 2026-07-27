class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int ssmaxi=INT_MIN;
        int product=0;
        for(int i=0;i<n;i++){
              if(maxi<=nums[i] && ssmaxi<=nums[i]){
               ssmaxi=maxi;
               maxi=nums[i];
              }
              else if(nums[i]>ssmaxi){
                ssmaxi=nums[i];
              }
        }
        product=(maxi-1)*(ssmaxi-1);
        return product;

    }
};