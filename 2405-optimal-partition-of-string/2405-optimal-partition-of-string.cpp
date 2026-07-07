class Solution {
public:
    int partitionString(string s) {
        vector<int> lastsubstring(26,-1);
        int cnt=0;
        int scs=0;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            if(lastsubstring[ch-'a']>=scs){
                cnt++;
                scs=i;
            }
            lastsubstring[ch-'a']=i;
        }
        return cnt+1;
    }
};