class Solution {
    bool dfs(int src,vector<vector<int>>&graph,int color,vector<int>&col)
    {
        col[src]=color;
        for(int adjNode:graph[src])
        {
            if(col[adjNode]==-1)
            {
              if(!(dfs(adjNode,graph,!color,col))) return false;
              
            }
            else if(col[adjNode]==color) return false; 
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int>col(n,-1);
        for(int i=0;i<n;i++)
        {
            if(col[i]==-1)
            {
                if(!dfs(i,graph,0,col)) return false;
            }
        }
        return true;
    }
};