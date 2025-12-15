class Solution {
    bool help(int src,vector<vector<int>>&graph,vector<int>&col,int curr)
    {
        col[src]=curr;
        queue<pair<int,int>>q;
        q.push({src,curr});
        while(!q.empty())
        {
           auto it=q.front();
           int node=it.first;
           int currCol=it.second;
           q.pop();
           for(auto adjNode:graph[node])
           {
               if(col[adjNode]==-1)
               {
                    col[adjNode]=!currCol;
                    q.push({adjNode,!currCol});
               }
               else if(currCol==col[adjNode]) return false;
           }
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