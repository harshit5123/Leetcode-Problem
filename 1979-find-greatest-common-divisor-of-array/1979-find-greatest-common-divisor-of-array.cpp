class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();
        int smallest=INT_MAX;
        int largest=INT_MIN;
        for(int i=0;i<n;i++){
            largest=max(largest,nums[i]);
            smallest=min(smallest,nums[i]);

        }
        return gcd(smallest,largest);
    }
};