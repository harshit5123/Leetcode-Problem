class Solution {
public:
    long long countCommas(long long n) {
        long long result=n;
        long long ans =0;
        long long lower=1000;
        int k=1;
        while(lower<=result){
        long long upper=lower*1000-1;
        long long count_in_range = min(result,upper)-lower+1;
        ans+=(long long)k*count_in_range;
        k++;
        lower*=1000;
                }

       return ans;
    }
};