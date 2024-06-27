class Solution {
    bool isPossible(int row,int col,int n,vector<string>&board)
    {
        int r=row;
        int c=col;
        while(c>=0)
        {
            if(board[r][c--]=='Q') return false; 
        }
         r=row;
        c=col;
        while(r>=0)
        {
            if(board[r--][c]=='Q') return false; 
        }
        r=row;
        c=col;
        while(r>=0 && c>=0)
        {
           if(board[r--][c--]=='Q') return false;
        }
        r=row;
        c=col;
         while(r>=0 && c<n)
        {
           if(board[r--][c++]=='Q') return false;
        }
        return true;
    }
    void solve(int row,int n,vector<string>board,vector<vector<string>>&ans)
    {
        if(row==n)
        {
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++)
        {
            if(isPossible(row,col,n,board))
            {
                board[row][col]='Q';
                solve(row+1,n,board,ans);
                board[row][col]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
     vector<string>board(n,string(n,'.'));
     vector<vector<string>>ans;
     solve(0,n,board,ans);
           return ans;
    }
};