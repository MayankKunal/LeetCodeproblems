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
       vector<vector<int>>dp(m+1,vector<int>(n+1,-1));

       return help(0,0,m,n,dp);   
    }
};