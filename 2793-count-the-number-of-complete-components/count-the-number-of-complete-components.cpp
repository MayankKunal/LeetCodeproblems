class Solution {
    void help(int node,vector<vector<int>>&Adj,vector<int>&vis,int & nodeCount)
    {
        if(vis[node]) return;
        vis[node]=1;
        nodeCount++;
        for(auto adjNode:Adj[node])
        {
            help(adjNode,Adj,vis,nodeCount);
        }
    }
    int  totalEdges(int node,vector<vector<int>>&Adj,vector<int>&vis,vector<int>&Degree)
    {
        if(vis[node]) return 0;
         
         vis[node]=1;
         int edges=Degree[node];
         for(auto adjNode:Adj[node])
         {
            edges+=totalEdges(adjNode,Adj,vis,Degree);
         }
         return edges;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>Adj(n);
        vector<int>Degree(n,0);
        for(auto edge:edges)
        {
            Adj[edge[0]].push_back(edge[1]);
            Adj[edge[1]].push_back(edge[0]);
            Degree[edge[0]]++;
            Degree[edge[1]]++;
        }

        vector<int>vis(n,0);
        vector<int>vis1(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                int nodeCount=0;
                  help(i,Adj,vis,nodeCount);
               
                int Edges=totalEdges(i,Adj,vis1,Degree);
                cout<<"No of Edges->"<<(Edges)/2<<" NodeCount->"<<nodeCount;
                    if((Edges/2)==((nodeCount)*(nodeCount-1))/2)
                    {
                        count++;
                    }
            }
        }
        return count;
    }
};