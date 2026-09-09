class Solution {
public:
    long long countCommas(long long n) {
        long long dup=n;
        long long ans=0;
        long long lower=1000;
        int k=1;
        while(lower<=dup){
            long long upper=lower*1000-1;
            long long count=min(dup,upper)-lower+1;
            ans+=(long long)k*count;
            lower=lower*1000;
            k++;
            
        }
        return ans;
    }
};