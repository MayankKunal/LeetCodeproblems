class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
    vector<vector<int>>ans(n,vector<int>(m,0));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 if(isWater[i][j]==1)
                 {
                    pq.push({0,{i,j}});
                    vis[i][j]=1;
                 }
            }
        }

int drow[4]={-1,0,1,0};
int dcol[4]={0,-1,0,1};
        while(!pq.empty())
        {
              auto it=pq.top();
              pq.pop();
              int val=it.first;
              int row=it.second.first;
              int col=it.second.second;
              for(int i=0;i<=3;i++)
              {
                int nrow=drow[i]+row;
                int ncol=dcol[i]+col;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol])
                {
                    vis[nrow][ncol]=1;
                    ans[nrow][ncol]=val+1;
                    pq.push({val+1,{nrow,ncol}});
                }
              }
        }
       return ans;
    }
};