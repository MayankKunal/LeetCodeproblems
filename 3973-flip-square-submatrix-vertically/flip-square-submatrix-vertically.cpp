class Solution {
    void help(vector<vector<int>>&grid,int row,int col,int k)
    {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=col;i<=min(col+k-1,m-1);i++)
        {
            int l=row,r=min(row+k-1,n-1);
            while(l<r)
            {
                swap(grid[l][i],grid[r][i]);
                l++;
                r--;
            }
        }
    }
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
          
          help(grid,x,y,k);

          return grid;

    }
};