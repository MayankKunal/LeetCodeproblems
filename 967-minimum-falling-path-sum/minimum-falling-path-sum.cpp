class Solution {
    int help(int row,int col,int n,int m,vector<vector<int>>&matrix,vector<vector<int>>&dp)
    {
        if(row>=n || row<0 ||col<0 || col>=m ) return INT_MAX;
        if(row==n-1 && col<m && col>=0) return matrix[row][col];
           if(dp[row][col]!=INT_MAX) return dp[row][col];
           
           int ans=INT_MAX;
           
           int down = matrix[row][col]+help(row + 1, col, n, m, matrix, dp);
int left = (col - 1 >= 0) ?matrix[row][col]+ help(row + 1, col - 1, n, m, matrix, dp) : INT_MAX;
int right = (col + 1 < m) ? matrix[row][col]+help(row + 1, col + 1, n, m, matrix, dp) : INT_MAX;

           ans=min(ans,min(down,min(left,right)));

           return dp[row][col]=ans;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
         if (n == 1 && m == 1) return matrix[0][0]; 
        vector<vector<int>>dp(n+1,vector<int>(m+1,INT_MAX));
      int ans=INT_MAX;
        for(int i=0;i<m;i++)
        {
            ans=min(ans,help(0,i,n,m,matrix,dp));
        }
        return ans;
    }
};