class Solution {
    void bfs(int src,vector<int>adj[],vector<int>temp,vector<vector<int>>&ans,vector<int>&vis)
    {
        queue<int>q;
        q.push(src);
        vis[src]=1;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            
            for(auto adjNode:adj[it])
            {
                if(!vis[adjNode])
                {
                    vis[adjNode]=1;
                temp.push_back(adjNode);
                q.push(adjNode);
                }
            }
        }
        sort(temp.begin(),temp.end());
        ans.push_back(temp);
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>adj[n];
        for(auto edge:edges)
        {
            adj[edge[1]].push_back(edge[0]);
        }
             
        for(int i=0;i<n;i++)
        {
            vector<int>vis(n+1,0);
            bfs(i,adj,temp,ans,vis);
        }
        return ans;
    }
};