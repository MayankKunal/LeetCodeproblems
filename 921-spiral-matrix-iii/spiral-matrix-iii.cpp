class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        vector<vector<int>>ans;
        ans.push_back({rStart,cStart});
        int steps=0;
        int d=0;
        while(ans.size()<rows*cols)
        {
                  if(d==0 || d==2) steps++;

                  for(int count=0;count<steps;count++)
                  {
                    rStart+=dir[d][0];
                    cStart+=dir[d][1];
                    if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols)
                    {
                        ans.push_back({rStart,cStart});
                    }
                  }
                  d=(d+1)%4;
        }
        return ans;
    }
};