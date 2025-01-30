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
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return help(0,0,n,m,grid,dp);
    }
};