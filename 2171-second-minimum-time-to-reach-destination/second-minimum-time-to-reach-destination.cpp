class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        vector<int>adj[n+1];
        for(auto edge:edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        vector<int>minDis(n+1,INT_MAX),secondMinDis(n+1,INT_MAX);
        minDis[1]=0;
        while(!pq.empty())
        {
              auto it=pq.top();
              pq.pop();
              int t=it.first;
              int node=it.second;
              if(node==n && secondMinDis[node]!=INT_MAX) return secondMinDis[node];
              int div=t/change;
              if((div%2)==1)
              {
                t=(div+1)*change;
              }
              for(auto adjNode:adj[node])
              {
                if(minDis[adjNode]>time+t)
                {  
                    secondMinDis[adjNode]=minDis[adjNode];
                    minDis[adjNode]=time+t;
                    pq.push({t+time,adjNode});
                }
                else if(secondMinDis[adjNode]>time+t && minDis[adjNode]!=time+t)
                {
                    secondMinDis[adjNode]=time+t;
                    pq.push({t+time,adjNode});
                }
              }
        }

        return -1;
    }
};