class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.length();
        string result="";
        vector<int>lastIndex(26,0);
        vector<bool>taken(26,false);
        for(int i=0;i<n;i++){
            int lastindex=s[i]-'a';
            lastIndex[lastindex]=i;
        }
        for(int i=0;i<n;i++){
            char ch=s[i];
            int idx=ch-'a';
            if(taken[idx]==true) continue;
            while((!result.empty()) && (result.back()>ch)&& lastIndex[result.back()-'a']>i){
                taken[result.back()-'a']=false;
                result.pop_back();
            }
            result.push_back(ch);
            taken[idx]=true;
        }
        return result;
    }
};