class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        
        int n=grid.size();
        int m=grid[0].size();
        priority_queue<long long>pq;
        
       
        for(int i=0;i<n;i++)
        {
            priority_queue<long long,vector<long long>,greater<long long>>pq1;
            for(int j=0;j<m;j++)
            {
               if(pq1.size()<limits[i])
               {
                pq1.push(grid[i][j]);
               }
               else
               {
                  if(!pq1.empty() && pq1.top()<grid[i][j])
                  {
                    pq1.pop();
                    pq1.push(grid[i][j]);
                  }
               }
            }

               while(!pq1.empty()) 
               {
                pq.push(pq1.top());
                pq1.pop();
               }
        }
        long long ans=0;
        while(k-- && !pq.empty())
        {
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};