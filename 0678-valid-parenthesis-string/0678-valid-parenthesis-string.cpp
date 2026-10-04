class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        int minopen=0;
        int maxopen=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                minopen++;
                maxopen++;
            }
            else if(s[i]==')'){
                minopen--;
                maxopen--;
            }
            else{
                minopen--;
                maxopen++;
            }
            if(maxopen<0) return false;
            minopen = max(0, minopen);
        }
     return minopen==0;
    }
};