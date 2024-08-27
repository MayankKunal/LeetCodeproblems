class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        
        vector<pair<int,double>>adj[n];
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        priority_queue<pair<double,int>>q;
        q.push({1.0,start_node});
        vector<double>p(n,0);
        p[start_node]=1;
        double ans=0;
        while(!q.empty())
        {
            auto it=q.top();
            q.pop();
            int node=it.second;
            double prob=it.first;
            if(node==end_node)
            {
                ans=max(ans,prob);
            }
            for(auto it:adj[node])
            {
                 int adjNode=it.first;
                 double pr=it.second;
                 if(p[adjNode]<(pr*prob))
                 {
                    p[adjNode]=(pr*prob);
                    q.push({(pr*prob),adjNode});
                 }
            }
        }
        return ans;
    }
};