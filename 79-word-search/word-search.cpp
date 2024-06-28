class Solution {
    bool help(int i,int row,int col,int k,int n,int m,string word,vector<vector<char>>&board,vector<vector<int>>&vis)
    {
        if(i==k)
        {
            return true;
        }
       if((row+1)<n && board[row+1][col]==word[i] && !vis[row+1][col])
       {
        vis[row+1][col]=1;
          if(help(i+1,row+1,col,k,n,m,word,board,vis)) return true;
          vis[row+1][col]=0;
       }
       if((row-1)>=0 && board[row-1][col]==word[i] && !vis[row-1][col])
       {
        vis[row-1][col]=1;
          if(help(i+1,row-1,col,k,n,m,word,board,vis)) return true;
          vis[row-1][col]=0;
       }
         if((col+1)<m && board[row][col+1]==word[i] && !vis[row][col+1])
       {
        vis[row][col+1]=1;
          if(help(i+1,row,col+1,k,n,m,word,board,vis)) return true;
          vis[row][col+1]=0;
       }
       if((col-1)>=0 && board[row][col-1]==word[i] && !vis[row][col-1])
       {
        vis[row][col-1]=1;
          if(help(i+1,row,col-1,k,n,m,word,board,vis)) return true;
          vis[row][col-1]=0;
       }
      return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int n=board.size();
        int m=board[0].size();
        int k=word.size();
        
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<m;j++)
            {  vector<vector<int>>vis(n+1,vector<int>(m+1,0));
                if(board[i][j]==word[0])
                {
                    vis[i][j]=1;
                   if(help(1,i,j,k,n,m,word,board,vis)) return true;
                }
            }
        }
        return false;
        

    }
};