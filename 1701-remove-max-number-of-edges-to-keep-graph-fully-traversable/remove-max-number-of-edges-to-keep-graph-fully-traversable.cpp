class Solution {
    int findParent(int x,vector<int>&parent)
    {
        if(x==parent[x]) return x;

        return findParent(parent[x],parent);
    }
    bool findUnion(int x,int y,vector<int>&graphSize,vector<int>&parent)
    {
        x=findParent(x,parent);
        y=findParent(y,parent);
        if(x==y) return false;

        if(graphSize[x]>=graphSize[y])
        {
            parent[y]=x;
            graphSize[x]+=graphSize[y];
        }
        else
        {
             parent[x]=y;
            graphSize[y]+=graphSize[x];
        }
        return true;
    }
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int>parentBob(n+1),parentAlice(n+1),graphSizeBob(n+1,1),graphSizeAlice(n+1,1);
        for(int i=1;i<=n;i++)
        {
            parentBob[i]=i;
            parentAlice[i]=i;
        }
        int edgeUsed=0;
          for(auto edge:edges)
          {
            if(edge[0]==3)
            {
                if(findUnion(edge[1],edge[2],graphSizeAlice,parentAlice)|findUnion(edge[1],edge[2],graphSizeBob,parentBob))
                {
                    edgeUsed++;
                }
            }
          }

          for(auto edge:edges)
          {
            if(edge[0]==1 && findUnion(edge[1],edge[2],graphSizeAlice,parentAlice)) edgeUsed++;
            if(edge[0]==2 && findUnion(edge[1],edge[2],graphSizeBob,parentBob)) edgeUsed++;
          }

          int checkAlice=findParent(1,parentAlice);
          int checkBob=findParent(2,parentBob);
          for(int i=1;i<=n;i++)
          {
            if((findParent(i,parentAlice)!=checkAlice) || (findParent(i,parentBob)!=checkBob)) return -1;
          }

          return edges.size()-edgeUsed;
    }
};