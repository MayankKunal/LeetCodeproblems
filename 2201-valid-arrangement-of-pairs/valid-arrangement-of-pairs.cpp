class Solution {
    void dfs(int node,unordered_map<int,int>&vis,unordered_map<int,vector<int>>&adj,vector<int>&ans)
    {
        ans.push_back(node);
        vis[node]=1;
        for(auto x:adj[node])
        {
            if(!vis[x]) 
            dfs(x,vis,adj,ans);
        }
    }
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        
        int n=pairs.size();
        unordered_map<int,vector<int>>adj;
        unordered_map<int,int>inDegree;
        unordered_map<int,int>outDegree;
vector<vector<int>>ans;
        for(auto pair:pairs)
        {
            adj[pair[0]].push_back(pair[1]);
            outDegree[pair[0]]++;
            inDegree[pair[1]]++;
        }
int startNode=pairs[0][0];
   for(auto &x:outDegree)
   {
     int node=x.first;
     if(outDegree[node]-inDegree[node]==1)
     {
      startNode=node;
      break;
     }
   }
   cout<<startNode;
   vector<int>res;
   stack<int>st;
   st.push(startNode);
   while(!st.empty())
   {
    int curr=st.top();
     if(!adj[curr].empty())
     {
        st.push(adj[curr].back());
        adj[curr].pop_back();
     }
     else
     {
        res.push_back(curr);
        st.pop();
     }
     
   }
   reverse(res.begin(),res.end());
for(int i=0;i<res.size()-1;i++)
{
    ans.push_back({res[i],res[i+1]});
}
        return ans;
    }
};