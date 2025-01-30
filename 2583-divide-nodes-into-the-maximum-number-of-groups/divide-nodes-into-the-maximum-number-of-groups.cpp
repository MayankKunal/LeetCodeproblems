class Solution {
    bool isBipartite(int node,unordered_map<int, vector<int>> &Adj ,vector<int>&colors,int col)
    {
        colors[node]=col;
        for(auto &adjNode:Adj[node])
        {
            if(colors[adjNode]==col) return false;
            if(colors[adjNode]==-1)
            {
                if(!isBipartite(adjNode,Adj,colors,!col))return false;
            }
        }
        return true;
    }
    int calMaxDepth(int i,unordered_map<int, vector<int>> &Adj ,int n)
    {
        vector<int>vis(n,0);
        vis[i]=1;
        int maxLevel=1;
        queue<int>q;
        q.push(i);
        while(!q.empty())
        {
            int n=q.size();
            while(n--)
            {
            int node=q.front();
            q.pop();
            for(auto &adjNode:Adj[node])
            {
                if(!vis[adjNode])
                {
                    vis[adjNode]=1;
                    q.push(adjNode);
                }
            }
            }
            maxLevel++;
        }
         
        return maxLevel-1;
    }
    int findAns(int node,unordered_map<int, vector<int>>&Adj,vector<int>&maxDepth,vector<int>&vis)
    {
             vis[node]=1;
             int ans=maxDepth[node];
             for(auto adjNode:Adj[node])
             {
                if(!vis[adjNode])
                {
                    ans=max(ans,findAns(adjNode,Adj,maxDepth,vis));
                }
             }
             
             return ans;
    }
    
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        
       unordered_map<int, vector<int>> adj; 
        for(auto edge:edges)
        {
            adj[edge[0]-1].push_back(edge[1]-1);
            adj[edge[1]-1].push_back(edge[0]-1);
        }
       vector<int>colors(n,-1);
        for(int i=0;i<n;i++)
        {
            if(colors[i]==-1)
           if(!isBipartite(i,adj,colors,0)) return -1;
        }

       vector<int>maxDepth(n,0);
        for(int i=0;i<n;i++)
        {
        
        maxDepth[i]=calMaxDepth(i,adj,n);

        }
        int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
               ans+=findAns(i,adj,maxDepth,vis);
            }
        }
        return ans;
        
    }
};