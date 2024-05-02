class Solution {
    void mark(int row,int col,int n,int m,vector<vector<int>>&grid)
    {
        if(row<0 || row>=n || col<0 || col>=m || grid[row][col]==1)
        {
            return;
        }
        grid[row][col]=1;

        mark(row+1,col,n,m,grid);
         mark(row-1,col,n,m,grid);
          mark(row,col+1,n,m,grid);
           mark(row,col-1,n,m,grid);
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==0)
            {
                mark(i,0,n,m,grid);
            }
            if(grid[i][m-1]==0)
            {
                mark(i,m-1,n,m,grid);
            }
        }

        for(int j=0;j<m;j++)
        {
            if(grid[0][j]==0)
            {
                mark(0,j,n,m,grid);
            }
            if(grid[n-1][j]==0)
              mark(n-1,j,n,m,grid);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
             if(grid[i][j]==0)
             {
                   count++;
                   mark(i,j,n,m,grid);
             }
            }
        }

        return count;
    }
};