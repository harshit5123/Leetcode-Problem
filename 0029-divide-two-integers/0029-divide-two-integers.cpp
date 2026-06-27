class Solution {
public:
    using ll=long long;
    int divide(int dividend, int divisor) {
        ll div=dividend;
        int sign=0;
        if (div<0){
            sign++;
            div=-div;
        } 
        ll d=divisor;
        if (d<0){
            sign++;
            d=-d;
        }
        ll res=0;

        while(div>=d){

            ll num=1;
            while(d*num<=div){
                num*=2;
            }

            res+=num/2;
            div-=(d*(num/2));
        }
        if (sign%2==1) res=-res;
        if (res > INT_MAX) res=INT_MAX;
        if (res < INT_MIN) res=INT_MIN;
        return res;
    }
};