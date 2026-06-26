class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int result=0;
        int prev=0;
        int curr=0;
        for(int i=0;i<n;i++){
            string s=bank[i];
            int cnt=0;
            for(int i=0;i<s.length();i++){
                if(s[i]=='1') cnt++;
            }
            if (curr>0) prev=curr;
            curr=cnt;
            result+=(curr*prev);

        }
        return result;
    }
};