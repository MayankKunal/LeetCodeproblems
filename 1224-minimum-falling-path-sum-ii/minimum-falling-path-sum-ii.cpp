class Solution {
    int help(int row,int n,int m,int prev,vector<vector<int>>&grid,vector<vector<int>>&dp)
    {
          if(row>=n) return 0;
         if(dp[row][prev]!=-1) return dp[row][prev];
          int ans=INT_MAX;
          for(int i=0;i<m;i++)
          {
            if(i==prev)
            {
            continue;
            }
            ans=min(ans,grid[row][i]+help(row+1,n,m,i,grid,dp));
          }

          return dp[row][prev]=ans;
          
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        int ans=INT_MAX;
        for(int i=0;i<m;i++)
        {
            ans=min(ans,grid[0][i]+help(1,n,m,i,grid,dp));
        }
        return ans;
    }
};