class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfWays(string corridor) {
        vector<int>indices;
        int n=corridor.length();
        for(int i=0;i<n;i++){
            if(corridor[i]=='S') indices.push_back(i);
        }
        if((indices.size()%2!=0) || indices.empty()) return 0;
        int prev=indices[1];
        long long result=1;
        for(int i=2;i<indices.size();i+=2){
            int curr=indices[i];
            int length=curr-prev;
            result=(result*length)%MOD;
            prev=indices[i+1];

        }
        return result;
    }
};