class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.length();
        int i=0;
        int j=0;
        int cnt=0;
        int maxcnt=0;
        while(j<n){
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
                cnt++;
            } 
           if(j-i+1==k){
               maxcnt=max(maxcnt,cnt);
               if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') cnt--;
               i++;
           }
           j++;
        }
        return maxcnt;
    }
};  