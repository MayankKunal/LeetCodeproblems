class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        unordered_map<int,vector<pair<int,int>>>graph;
        for(auto flight:flights)
        {
            graph[flight[0]].push_back({flight[1],flight[2]});
        }

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({0,{0,src}});
        vector<vector<int>>dis(n,vector<int>(k+2,INT_MAX));
        dis[src][0]=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int cost=it.first;
            int move=it.second.first;
            int node=it.second.second;
            if(move>k+1) continue;
            if(node==dst) return cost; 
            for(auto adj:graph[node])
            {
                int adjNode=adj.first;
                int c=adj.second;
                
                if(dis[adjNode][move]>(c+cost))
                {
                    dis[adjNode][move]=(c+cost);
                    pq.push({(c+cost),{move+1,adjNode}});
                }
            }
        }
        return -1;
    }
};