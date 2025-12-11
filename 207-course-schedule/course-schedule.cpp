class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n=numCourses;
        unordered_map<int,vector<int>>graph;
        vector<int>inDegree(n,0);
        for(auto x:prerequisites)
        {
            graph[x[1]].push_back(x[0]);
            inDegree[x[0]]++;
        }
        queue<int>q;
        vector<int>vis(n,0);
     for(int i=0;i<n;i++)
     {
        if(inDegree[i]==0)
        {
            q.push(i);
            vis[i]=true;
        }
     }
     while(!q.empty())
     {
        int node=q.front();
        
        q.pop();
        for(auto x:graph[node])
        {
            inDegree[x]--;
            if(inDegree[x]==0 && !vis[x])
            {
                vis[x]=1;
                q.push(x) ;
            }
        }
     }
     for(int x:inDegree)
     {
        if(x!=0) return false;
     }

      return true;

    }
};