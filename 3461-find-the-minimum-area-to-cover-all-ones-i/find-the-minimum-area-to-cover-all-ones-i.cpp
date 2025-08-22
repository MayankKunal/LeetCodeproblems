class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int minX=INT_MAX,maxX=0;
        int minY=INT_MAX,maxY=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
               if(grid[i][j]==1)
               {
                minX=min(minX,j);
                minY=min(minY,i);
                maxX=max(maxX,j);
                maxY=max(maxY,i);
               }
            }

        }
           
        return abs(maxX+1-minX)*abs(maxY+1-minY);
    }
};