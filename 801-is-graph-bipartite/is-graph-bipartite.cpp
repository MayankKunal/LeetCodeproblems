class Solution {
    bool help(int src,vector<vector<int>>&graph,vector<int>&col,int curr)
    {
        col[src]=curr;
       
       for(auto adjNode:graph[src])
       {
          if(col[adjNode]==-1)
          {
            col[adjNode]=!curr;
             if(!help(adjNode,graph,col,!curr)) return false;
          }
          else if(col[adjNode]==curr) return false;
       }
       return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int>col(n,-1);
        
        for(int i=0;i<n;i++)
        {
            int curr=0;
            if(col[i]==-1)
            if(!help(i,graph,col,curr)) return false;
        }
        return true;
    }
};