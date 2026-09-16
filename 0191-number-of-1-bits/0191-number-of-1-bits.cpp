class Solution {
public:
    int hammingWeight(int n) {
        string res="";
        while(n>0){
            int rem=n%2;
            res+=to_string(rem);
            n=n/2;
        }
        reverse(res.begin(),res.end());
        int cnt=0; 
        for(int i=0;i<res.length();i++){
            if(res[i]=='1') cnt++;
        }
        return cnt;
    }
};