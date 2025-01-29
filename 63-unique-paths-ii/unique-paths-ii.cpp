class Solution {
    int help(int row,int col,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
        if(row>=n || col>=m || grid[row][col]==1) return 0;
        if(row==n-1 && col==m-1) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        return dp[row][col]=help(row+1,col,n,m,grid,dp)+help(row,col+1,n,m,grid,dp);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return help(0,0,n,m,obstacleGrid,dp);
    }
};