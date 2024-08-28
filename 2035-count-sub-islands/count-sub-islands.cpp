class Solution {
    bool isSubisland(int i,int j,int n,int m,vector<vector<int>>&grid1,vector<vector<int>>&grid2,vector<vector<int>>&vis)
    {
        if(grid1[i][j]==0) return false;
        vis[i][j]=1;
        bool left=true;
        if((i-1)>=0 && !vis[i-1][j] && grid2[i-1][j]==1)
        { left=isSubisland(i-1,j,n,m,grid1,grid2,vis);}
        bool right=true;
        if((i+1)<n && !vis[i+1][j] && grid2[i+1][j]==1) right=isSubisland(i+1,j,n,m,grid1,grid2,vis);
        bool up=true;
        if((j-1)>=0 && !vis[i][j-1] && grid2[i][j-1]==1) up=isSubisland(i,j-1,n,m,grid1,grid2,vis);
        bool down=true;
        if((j+1)<m && !vis[i][j+1] && grid2[i][j+1]==1) down=isSubisland(i,j+1,n,m,grid1,grid2,vis);
return left&right&up&down;
    }
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        
        int n=grid2.size();
        int m=grid2[0].size();
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
    int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1 && !vis[i][j])
                {
                    if(isSubisland(i,j,n,m,grid1,grid2,vis)) count++;
                }
            }
        }
        return count;
    }
};