class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        int dr[8]={0,0,1,1,1,-1,-1,-1};
        int dc[8]={-1,1,-1,1,0,-1,1,0};
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
       if(grid[0][0]==1) return -1;
        pq.push({1,{0,0}});
       while(!pq.empty())
       {
        auto it=pq.top();
        pq.pop();
        int dis=it.first;
        int row=it.second.first;
        int col=it.second.second;
         if(row==n-1 && col==m-1) return dis;
        for(int i=0;i<8;i++)
        {
            int nrow=row+dr[i];
            int ncol=col+dc[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0)
            {
                   grid[nrow][ncol]=1;
                   pq.push({dis+1,{nrow,ncol}});
            }
        }
       }
          
          return -1;

    }
};