class Solution {
public:
    void solve(int open ,int close,int n,vector<string>&result,string curr){
        if(open==n && close==n) {
            result.push_back(curr);
            return;
        }
        if(open<n){
            solve(open+1,close,n,result,curr+'(');
        }
        if(close<open){
            solve(open,close+1,n,result,curr+')');
        }
    }
    vector<string> generateParenthesis(int n) {
       vector<string>result;
       string curr="";
       solve(0,0,n,result,curr);
       return result;


    }
};