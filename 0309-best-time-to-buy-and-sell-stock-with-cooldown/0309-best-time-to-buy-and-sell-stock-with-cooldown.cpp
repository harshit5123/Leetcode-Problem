class Solution {
public:
    int f(int i,int buy,vector<int>& prices,vector<vector<int>>&dp){
        int n=prices.size();
        if(i>=n) return 0;
        int profit=0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
           profit+=max(-prices[i]+f(i+1,0,prices,dp),f(i+1,1,prices,dp));
        }
        else{
            profit+=max(prices[i]+f(i+2,1,prices,dp),f(i+1,0,prices,dp));
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return f(0,1,prices,dp);
        //tabulation
        vector<int>front2(2,0);
        vector<int>front1(2,0);
        vector<int>cur(2,0);
        for(int i=n-1;i>=0;i--){
            cur[1]=max(-prices[i]+front1[0],front1[1]);
            cur[0]=max(prices[i]+front2[1],front1[0]);

            front2=front1;
            front1=cur;
        }
        
    
        return cur[1];
    }
};