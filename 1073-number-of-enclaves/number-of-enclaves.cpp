class Solution {
    void dfs(int row,int col,int n,int m,vector<vector<int>>&grid)
    {
        if(row>=n || row<0 || col>=m  || col<0 || grid[row][col]!=1)
        {
            return;
        }
        grid[row][col]=0;
        dfs(row+1,col,n,m,grid);
        dfs(row-1,col,n,m,grid);
        dfs(row,col+1,n,m,grid);
        dfs(row,col-1,n,m,grid);
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
            {
                dfs(i,0,n,m,grid);
            }
            if(grid[i][m-1]==1)
            {
                dfs(i,m-1,n,m,grid);
            }
        }

        for(int j=0;j<m;j++)
        {
            if(grid[0][j]==1)
            {
                dfs(0,j,n,m,grid);
            }
            if(grid[n-1][j]==1)
            {
                dfs(n-1,j,n,m,grid);
            }
        }
 int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) count++;
            }
        }
        return count;
    }
};