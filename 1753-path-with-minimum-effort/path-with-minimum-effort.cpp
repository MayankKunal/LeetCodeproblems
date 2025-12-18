class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        
        int n=heights.size();
        int m=heights[0].size();

        int dr[4]={0,-1,0,1};
        int dc[4]={1,0,-1,0};

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});

        vector<vector<int>>cos(n+1,vector<int>(m+1,INT_MAX));
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int cost=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1 && col==m-1) return cost;
            for(int i=0;i<4;i++)
            {
                int nrow=row+dr[i];
                int ncol=col+dc[i];
               
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                    if(max(abs(heights[nrow][ncol]-heights[row][col]),cost)<cos[nrow][ncol])
                    {
                        cos[nrow][ncol]=max(abs(heights[nrow][ncol]-heights[row][col]),cost);
                         pq.push({cos[nrow][ncol],{nrow,ncol}});         
                    }
                }
            }
        }

        return -1;
        
    }
};