class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>adj[n];
        vector<int>incoming(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto it:graph[i])
            {
                adj[it].push_back(i);
                    incoming[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
         if(incoming[i]==0)
         {
                  q.push(i);
         }
        }
        vector<int>ans;
        while(!q.empty())
        {
           int node=q.front();
           q.pop();
           ans.push_back(node);
           for(auto x:adj[node])
           {
               incoming[x]--;

               if(incoming[x]==0)
               {
                   q.push(x);
               }
           }
           
        }
if(ans.size())
{
        sort(ans.begin(),ans.end());
        return ans;
    }
    return {};
    }
};