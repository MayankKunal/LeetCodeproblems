class Solution {
public:
 vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
       pq.push({0,{0,0}});
       vector<vector<int>>minCost(n,vector<int>(m,INT_MAX));
        minCost[0][0]=0;
       while(!pq.empty())
       {
        auto it=pq.top();
        pq.pop();
        int currCost=it.first;
        int row=it.second.first;
        int col=it.second.second;
       
        for(int i=0;i<=3;i++)
        {
            int newRow=row+dir[i][0];
            int newCol=col+dir[i][1];
            if(newRow>=0 && newRow<n && newCol>=0 && newCol<m)
            {
               int newCost = currCost + (i != (grid[row][col] - 1) ? 1 : 0);
                if(minCost[newRow][newCol]>newCost)
                {
                    minCost[newRow][newCol]=newCost;
                    pq.push({newCost,{newRow,newCol}});
                }

            }
        }
       }

       return minCost[n-1][m-1];
    }
};