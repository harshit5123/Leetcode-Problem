class Solution {
public:
    int minRotations(string s) {
        int n=s.length();
        int rot=0;
        int curr=0;
        for(int i=0;i<n;i++){
            int d=(s[i]-'0')-curr;
            int cost=abs(d);
            int ans=min(cost,10-cost);
            rot+=ans;
            curr=s[i]-'0';
        }
    return rot;
    }
};