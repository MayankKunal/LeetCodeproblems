class Solution {
    bool help(int node,unordered_map<int,vector<int>>&graph,vector<int>&vis,vector<int>&pathVis)
    {
        vis[node]=1;
        pathVis[node]=1;
        for(auto adjNode:graph[node])
        {
            if(!vis[adjNode])
            {
                vis[adjNode]=1;
                if(!help(adjNode,graph,vis,pathVis)) return false;
            }
            if(pathVis[adjNode]) return false;
        }
        pathVis[node]=0;
        return true;

    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n=numCourses;
        unordered_map<int,vector<int>>graph;
        vector<int>inDegree(n,0);
        for(auto x:prerequisites)
        {
            inDegree[x[0]]++;
            graph[x[1]].push_back(x[0]);
        }
       
        vector<int>vis(n,0);
      vector<int>pathVis(n,0);
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                if(!help(i,graph,vis,pathVis)) return false;
            }
        }
        return true;
    }
};