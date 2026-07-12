class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        long long totalsum=accumulate(nums.begin(),nums.end(),0ll);
        long long leftsum=0;
        int mini=INT_MAX;
        int index=0;
        for(int i=0;i<n;i++){
          leftsum+=nums[i];
          long long rightsum=totalsum-leftsum;
          long long avg1=leftsum/(i+1);
          long long  avg2=0;
          if(i==n-1) avg2=0;
          else avg2=rightsum/(n-(i+1));
          
          long long diff=abs(avg1-avg2);
          if(diff<mini){
            mini=diff;
            index=i;
          }


        }
        return index;
    }
};