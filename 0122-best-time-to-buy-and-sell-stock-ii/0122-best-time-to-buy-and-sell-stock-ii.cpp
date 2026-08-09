class Solution {
public:
    int f(int i,int buy,vector<int>& prices,vector<vector<int>>&dp){
        int n=prices.size();
        if(i==n) return 0;
        int profit=0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
           profit+=max(-prices[i]+f(i+1,0,prices,dp),f(i+1,1,prices,dp));
        }
        else{
            profit+=max(prices[i]+f(i+1,1,prices,dp),f(i+1,0,prices,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        //return f(0,1,prices,dp);
        //tabulation
        int aheadnotbuy=0; int aheadbuy=0;
        for(int i=n-1;i>=0;i--){
            int curbuy=max(-prices[i]+aheadnotbuy,aheadbuy);
            int notcurbuy=max(prices[i]+aheadbuy,aheadnotbuy);

            aheadnotbuy=notcurbuy;
            aheadbuy=curbuy;
        }
    
        return aheadbuy;
    }
};