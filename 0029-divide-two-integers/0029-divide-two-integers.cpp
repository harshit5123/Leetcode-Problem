class Solution {
public:
    int divide(int dividend, int divisor) {
        long long div=dividend;
        long long d=divisor;
        long long ans=div/d;
        if (ans > INT_MAX) ans=INT_MAX;
        if (ans < INT_MIN) ans=INT_MIN;
        return ans;
    }
};