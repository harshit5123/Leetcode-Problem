class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int j=0;j<m;j++) dp[0][j]=matrix[0][j];
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int down=matrix[i][j]+dp[i-1][j];
                int left=1e9;
                if(j-1>=0) left=matrix[i][j]+dp[i-1][j-1];
                int right=1e9;
                if(j+1<m) right=matrix[i][j]+dp[i-1][j+1];
                dp[i][j]=min(down,min(left,right));
            }
        }
    int ans=INT_MAX;
    for(int j=0;j<n;j++){
        ans=min(ans,dp[n-1][j]);
    }
    return ans;
    }
};