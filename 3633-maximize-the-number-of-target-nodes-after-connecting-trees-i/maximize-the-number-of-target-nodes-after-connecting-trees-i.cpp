class Solution {
    int help(int src,unordered_map<int,vector<int>>&Adj,int parent,int k)
    {
       if(k==0) return 1;
           int count=1;
           for(auto adjNode:Adj[src])
           {
            if(adjNode!=parent)
            {
                count+=help(adjNode,Adj,src,k-1);
            }
           }

           return count;
    }

    

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n=edges1.size();
        int m=edges2.size();
        vector<int>numOfNode1(n+1);
      
        unordered_map<int,vector<int>>adj1;
           unordered_map<int,vector<int>>adj2;

         for(auto edge:edges1)
         {
            adj1[edge[0]].push_back(edge[1]);
             adj1[edge[1]].push_back(edge[0]);
         }

         for(auto edge:edges2)
         {
            adj2[edge[0]].push_back(edge[1]);
             adj2[edge[1]].push_back(edge[0]);
         }
         int c=0;

        for(int i=0;i<=n;i++)
        {
            
             
              numOfNode1[i]= help(i,adj1,-1,k);
        }
      int maxCount=0;
        for(int i=0;i<=m;i++)
        {
         
            
              maxCount=max(help(i,adj2,-1,k-1),maxCount);
        }
          vector<int>ans(n+1,1);
          if(k==0) return ans;
        for(int i=0;i<=n;i++)
        {
        //   cout<<numOfNode1[i]<<" "<<maxCount;
            ans[i]=(numOfNode1[i]+maxCount);
        }
        return ans;
    }
};