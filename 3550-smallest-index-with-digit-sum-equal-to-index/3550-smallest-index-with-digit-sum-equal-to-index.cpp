class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int num=nums[i];
            int res=0;
            while(num>0){
                int lastdigit=num%10;
                res+=lastdigit;
                num=num/10;
                }
            if(res==i) return i;

        }
        return -1;
    }
};