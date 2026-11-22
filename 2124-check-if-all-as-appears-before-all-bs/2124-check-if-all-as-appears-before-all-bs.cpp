class Solution {
public:
    bool checkString(string s) {
        int n=s.length();
        int idx=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='b') {
                idx=i;
                break;
            }
        }
        if(idx>=0){
        for(int i=idx;i<n;i++){
             if(s[i]=='a') return false;
        }
    }
        if(idx==-1) return true;
        return true;
    }
};