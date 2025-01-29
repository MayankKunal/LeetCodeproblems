class Solution {
    int findParent(int Node,vector<int>&parent)
    {
          if(parent[Node]==Node) return Node;

          return parent[Node]=findParent(parent[Node],parent);
    }
    bool add(vector<int>edge,vector<int>&parent,vector<int>&graphSize)
    {
        int Node1=edge[0];
        int Node2=edge[1];
         int p1=findParent(Node1,parent);
        int p2=findParent(Node2,parent);
        if(p1==p2)
            return false;
        if(graphSize[p1]>=graphSize[p2])
        {
            parent[p2]=p1;
            graphSize[p1]+=graphSize[p2];
        }
        else
        {
            parent[p1]=p2;
            graphSize[p2]+=graphSize[p1];
        }
        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int>parent(n+1);
        for(int i=1;i<=n;i++)
        {
            parent[i]=i;
        }
        vector<int>graphSize(n+1,1);
        for(auto edge:edges)
        {
            if(!add(edge,parent,graphSize))
            return edge;
        }
        return {-1,-1};
    }
};