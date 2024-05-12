class Solution {
    int findMax(int row,int col,vector<vector<int>>&grid)
    {
        int maxEle=0;
        for(int i=row;i<row+3;i++)
        {
            for(int j=col;j<col+3;j++)
            {
                maxEle=max(maxEle,grid[i][j]);
            }
        }
        return maxEle;
    }
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>ans(n-2,vector<int>(m-2,0));
        for(int i=0;i<n-2;i++)
        {
     for(int j=0;j<m-2;j++)
     {
            ans[i][j]=findMax(i,j,grid);
     }
        }
        return ans;
    }
};