class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n=nums.size();
        int cnt1=0;
        int min_op=1000;
        for (int i=0;i<n;i++){
            if (nums[i]==1) cnt1++;
            int g=nums[i];
            for (int j=i+1;j<n;j++){
                g=gcd(g,nums[j]);
                if (g==1){
                    min_op=min(min_op,n-1+(j-i));
                    break;
                }
            }
        }
        if (min_op==1000) return -1;
        return min_op-cnt1;
    }
};