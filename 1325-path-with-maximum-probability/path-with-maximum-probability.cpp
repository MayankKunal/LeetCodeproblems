class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        int m=edges.size();
        unordered_map<int,vector<pair<int,double>>>graph;

        for(int i=0;i<m;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            graph[u].push_back({v,succProb[i]});
            graph[v].push_back({u,succProb[i]});
        }



        priority_queue<pair<double,int>>q;
        q.push({1.0,start_node});
    double ans=0.0;
    vector<double>success(n,0.0);
    success[start_node]=1.0;
        while(!q.empty())
        {
            auto it=q.top();
            q.pop();
            double prob=it.first;
            int node=it.second;
            if(node==end_node)
            ans=max(ans,prob);
            for(auto adj:graph[node])
            {

                double sucP=adj.second;
                int adjNode=adj.first;
                if((sucP*prob)>(success[adjNode]))
                {
                    success[adjNode]=(sucP*prob);
                      q.push({(sucP*prob),adjNode});
                }
            }
        }
        return ans;
    }
};