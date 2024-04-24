class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>q;
        int n=mat.size();
        int m=mat[0].size();
          vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                q.push({0,{i,j}});
                vis[i][j]=1;
                }
            }
        }
  int dcol[4]={0,-1,0,1};
  int drow[4]={-1,0,1,0};
        while(!q.empty())
        {
            auto it=q.top();
            q.pop();
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;
            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]==1 && 
                !vis[nrow][ncol])
                {
                       q.push({dis+1,{nrow,ncol}});
                       mat[nrow][ncol]=dis+1;
                       vis[nrow][ncol]=1;
                }
            }
        }

        return mat;
    }
};