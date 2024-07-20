class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {

            int row=rowSum.size();
            int col=colSum.size();
            vector<vector<int>>arr(row,vector<int>(col,0));
            int i=0,j=0;
        while(i<row && j<col)
        {
           int val=min(rowSum[i],colSum[j]);
           arr[i][j]=val;
           rowSum[i]-=val;
           colSum[j]-=val;
           if(rowSum[i]==0) i++;
           if(colSum[j]==0) j++;
        } 
        return arr;
    }
};