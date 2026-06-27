class Solution {
public:
    int divide(int dividend, int divisor) {
        long long div=dividend;
        long long d=divisor;
        long long ans=div/d;
        long long maxi=INT_MAX;
        long long mini=INT_MIN;
        if (ans > maxi) ans=INT_MAX;
        if (ans < mini) ans=INT_MIN;
        return ans;
    }
};