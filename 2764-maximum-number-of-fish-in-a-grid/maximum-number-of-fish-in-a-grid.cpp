class Solution {
    int help(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&vis)
    {
        if(i<0 || i>=n || j<0 || j>=m  || grid[i][j]==0 || vis[i][j]==1) return 0;
           vis[i][j]=1;
        return grid[i][j]+help(i+1,j,n,m,grid,vis)+help(i-1,j,n,m,grid,vis)+help(i,j+1,n,m,grid,vis)+help(i,j-1,n,m,grid,vis);
    }
public:
    int findMaxFish(vector<vector<int>>& grid) {

      int n=grid.size();
      int m=grid[0].size();
      int ans=0;
       vector<vector<int>>vis(n+1,vector<int>(m+1,0));
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]!=0 && !vis[i][j])
            {
              ans=max(ans,help(i,j,n,m,grid,vis));
            }
        }
       }

       return ans;

    }
};