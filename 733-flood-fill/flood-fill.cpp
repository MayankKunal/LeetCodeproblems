class Solution {
    void dfs(vector<vector<int>>&image,int sr,int sc,int colr,int color)
    {
    if(sr>=image.size() || sr<0 || sc>=image[0].size() || sc<0) return;
  if(image[sr][sc]!=colr) return;
  if(image[sr][sc]==color) return;
        image[sr][sc]=color;
        // vis[sr][sc]=1;
        dfs(image,sr+1,sc,colr,color);
         dfs(image,sr-1,sc,colr,color);
          dfs(image,sr,sc+1,colr,color);
           dfs(image,sr,sc-1,colr,color);

    }
void bfs(vector<vector<int>>&image,int sr,int sc,int color)
{
    int colr=image[sr][sc];
  queue<pair<int,int>>q;
  int n=image.size();
  int m=image[0].size();
//   vector<vector<int>>visited(n+1,vector<int>(m+1,0));
  q.push({sr,sc});
  int drow[4]={0,-1,0,1};
  int dcol[4]={-1,0,1,0};
  image[sr][sc]=color;
//   visited[sr][sc]=1;
  while(!q.empty())
  {
    auto it=q.front();
    q.pop();
    int row=it.first;
    int col=it.second;
    // image[row][col]=color;
    for(int i=0;i<4;i++)
    {
        int nrow=row+drow[i];
        int ncol=col+dcol[i];
        if(nrow>=0 && nrow<image.size() && ncol>=0 && ncol<image[0].size()&&image[nrow][ncol]==colr && image[nrow][ncol]!=color)
        {
            q.push({nrow,ncol});
            // visited[nrow][ncol]=1;
            image[nrow][ncol]=color;
        }
    }
  }
}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //    bfs(image,sr,sc,color);
        int n=image.size();
        int m=image[0].size();
       
        int colr=image[sr][sc];
        dfs(image,sr,sc,colr,color);
           return image; 
    }
};