class Solution {
    void help(int node,vector<int>adj[],vector<int>&vis)
    {
        if(vis[node]) return;

        vis[node]=1;
        for(int adjNode:adj[node])
        {
              help(adjNode,adj,vis);
        }  
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
        int count=0;
        vector<int>vis(n+1,0);
        vector<int>adj[n+1];
//   int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            
                if(isConnected[i][j]==1)
                {
                  adj[i+1].push_back(j+1);
                }
            }
        
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                count++;
               help(i,adj,vis);
            }
        }
        return count;
}
};