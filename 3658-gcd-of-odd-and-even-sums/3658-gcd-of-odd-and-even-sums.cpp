class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int sumeven=0;
        int sumodd=0;
    for(int i=1;i<=2*n;i++){
        if(i%2==0) sumeven+=i;
        if(i%2==1) sumodd+=1;
    }
    return gcd(sumeven,sumodd);
    }
};