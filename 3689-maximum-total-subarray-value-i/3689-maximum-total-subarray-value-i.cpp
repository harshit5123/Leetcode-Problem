class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans=0;
        long long n=nums.size();
        long long maxelem=*max_element(nums.begin(),nums.end());  //O(n)
        long long minelem=*min_element(nums.begin(),nums.end());   //O(n)
        long long result=maxelem-minelem;
        ans=k*result;   
        return ans;
    }
};