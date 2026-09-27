class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.length();
        stack<int>st;
        string res="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(res.length());
            }
            else if(s[i]==')'){
                int l=st.top();
                reverse(res.begin()+l,res.end());
                st.pop();
            }
            else{
                res.push_back(s[i]);
            }
        }
        return res;
    }
};