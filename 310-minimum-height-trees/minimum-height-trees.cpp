class Solution {
    
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(edges.size()==0) return {0};
      vector<int>adj[n];
      vector<int>indegree(n,0);
      for(auto edge:edges)
      {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
        indegree[edge[0]]++;
        indegree[edge[1]]++;
      }
       
       queue<int>q;
       for(int i=0;i<n;i++)
       {
        if(indegree[i]==1)
        {
            q.push(i);
        }
       }

       while(n>2)
       {
        int k=q.size();
       n-=k;
       while(k--)
       {
        int currNode=q.front();
        q.pop();
        for(int adjNode:adj[currNode])
        {
            indegree[adjNode]--;
            if(indegree[adjNode]==1)
            {
                q.push(adjNode);
            }
        }
       }
       }
  vector<int>ans;
       while(!q.empty())
       {
        ans.push_back(q.front());
        q.pop();
       }
       return ans;
    }
};