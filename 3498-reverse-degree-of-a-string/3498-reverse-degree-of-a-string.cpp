class Solution {
public:
    int reverseDegree(string s) {
        int n=s.length();
        int sum=0;
        for(int i=0;i<n;i++){
            int revind='z'- (s[i]-1);
            sum+=(i+1)*revind;
        }
        return sum;
    }
};