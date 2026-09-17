class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        int i=0;
        int j=1;
        int k=2;
        int index=0;
        while(j<n){
            int sum=nums[i]+nums[j];
            if(st.find(sum)!=st.end()) return true;
            st.insert(sum);
            i++;
            j++;
        }
        return false;

    }
};