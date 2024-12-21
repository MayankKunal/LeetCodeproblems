class Solution {
    int help(int node,int parent,vector<int>Adj[],int k,int&ans, vector<int>& values)
    {  int sum=0;
        for(auto x:Adj[node])
        {
            if(x!=parent)
            {
                sum+=help(x,node,Adj,k,ans,values);
            }
            sum=sum%k;
        }
        sum+=values[node];
        if(sum%k==0)
        ans++;
        return sum;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
          vector<int>Adj[n];
          for(auto edge:edges)
          {
            Adj[edge[0]].push_back(edge[1]);
            Adj[edge[1]].push_back(edge[0]);
          }
int ans=0;
  help(0,-1,Adj,k,ans,values);
  return ans;


    }
};