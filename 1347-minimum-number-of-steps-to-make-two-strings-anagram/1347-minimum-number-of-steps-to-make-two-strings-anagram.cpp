class Solution {
public:
    int minSteps(string s, string t) {
        vector<int>lower1(26,0);
        vector<int>lower2(26,0);
        int ans=0;
        for(int i=0;i<s.length();i++){
            lower1[s[i]-'a']++;
            lower2[t[i]-'a']++;
        }
        if(lower1==lower2) return 0;
        for(int i=0;i<26;i++){
            if(lower1[i]-lower2[i]<0) continue;
            else ans+=(lower1[i]-lower2[i]);
        }
        return ans;
    }
};