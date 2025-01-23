class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int isloated=0;
        unordered_map<int,int>row;
        unordered_map<int,int>col;
        int total=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    total++;
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int isolated=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    if(row[i]==1 && col[j]==1)
                    {
                        isolated++;
                    }
                }
            }
        }
        return total-isolated;
    }
};