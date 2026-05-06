class Solution {

    bool isValid(int row,int col,int n,vector<string>& board)
    {
        // upper-left diagonal
        int r = row - 1;
        int c = col - 1;

        while(r >= 0 && c >= 0)
        {
            if(board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        // upper-right diagonal
        r = row - 1;
        c = col + 1;

        while(r >= 0 && c < n)
        {
            if(board[r][c] == 'Q') return false;
            r--;
            c++;
        }

        // same column
        r = row - 1;

        while(r >= 0)
        {
            if(board[r][col] == 'Q') return false;
            r--;
        }

        return true;
    }

    void solve(int row,int n,vector<string>& board,
               vector<vector<string>>& ans)
    {
        if(row == n)
        {
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++)
        {
            if(isValid(row,col,n,board))
            {
                board[row][col] = 'Q';

                solve(row + 1,n,board,ans);

                board[row][col] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>> ans;

        vector<string> board(n,string(n,'.'));

        solve(0,n,board,ans);

        return ans;
    }
};