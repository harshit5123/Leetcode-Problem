class Solution {
public:
    bool checkpalindrome(string &res){
        int n=res.length();
        int i=0;
        int j=n-1;
        while(i<j){
            if(res[i]!=res[j]){
                return false;
            }
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    bool isPalindromic(string s) {
        int n=s.length();
        string res="";
        for(int i=0;i<n;i++){
            int a=s[i];
            while(a>0){
                int rem=a%2;
                res+=to_string(rem);
                a=a/2;
            }
        }
            res+=to_string(0);
            reverse(res.begin(),res.end());
            bool ans=checkpalindrome(res);
            return ans;
    }
};