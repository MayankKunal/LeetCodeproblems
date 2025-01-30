class Solution {
    int help(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(i>=n || j>=m) return 1e9;
        if(i==n-1 && j==m-1) return grid[i][j];

        if(dp[i][j]!=-1) return dp[i][j];

        return dp[i][j]=grid[i][j]+min(help(i+1,j,n,m,grid,dp),help(i,j+1,n,m,grid,dp));
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // return help(0,0,n,m,grid,dp);
        dp[0][0]=grid[0][0];
        for(int i=1;i<n;i++)
        {
            dp[i][0]=dp[i-1][0]+grid[i][0];
        }
        for(int i=1;i<m;i++)
        {
            dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};