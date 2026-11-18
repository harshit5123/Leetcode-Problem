class Solution {
public:
    int minChanges(string s) {
        int n=s.length();
        int minop=0;
        int rem=0;
        for(int i=0;i<n;i+=2){
            rem=s[i];
            if(s[i+1]!=rem) minop++;
        }
        return minop;


    }
};