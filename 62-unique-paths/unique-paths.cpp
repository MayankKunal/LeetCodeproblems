class Solution {
    int help(int row,int col,int n,int m,vector<vector<int>>&dp)
    {
        if(row>=n || col>=m) return 0;
        if(row==n-1 && col==m-1) return 1;
        if(dp[row][col]!=-1) return dp[row][col];
        return dp[row][col]=help(row+1,col,n,m,dp)+help(row,col+1,n,m,dp);
    }
public:
    int uniquePaths(int m, int n) {
    //    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
       vector<vector<int>>dp(m+1,vector<int>(n+1,1));
       for(int i=1;i<m;i++)
       {
        for(int j=1;j<n;j++)
        {
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
       }
       return dp[m-1][n-1];   
    }
};