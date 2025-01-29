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
         Node1=findParent(Node1,parent);
        Node2=findParent(Node2,parent);
        if(Node1==Node2)
            return false;
        if(graphSize[Node1]>=graphSize[Node2])
        {
            parent[Node2]=Node1;
            graphSize[Node1]+=graphSize[Node2];
        }
        else
        {
            parent[Node1]=Node2;
            graphSize[Node2]+=graphSize[Node1];
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