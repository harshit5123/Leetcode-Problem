class Solution {
public:
    bool checkDivisibility(int n) {
        int num=n;
        int sum=0;
        int product=1;
        while(n>0){
            int lastdigit=n%10;
            sum+=lastdigit;
            product*=lastdigit;
            n=n/10;
        }
        int divisor=sum+product;
        return (num%divisor==0);
    }
};