class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans="";
        int n=nums[0].size();
        int i=0;
        for (auto str:nums){
            char ch=str[i];
            if (ch=='1') ans+='0';
            if (ch=='0') ans+='1';
            i++;
        }
        return ans;
    }
};