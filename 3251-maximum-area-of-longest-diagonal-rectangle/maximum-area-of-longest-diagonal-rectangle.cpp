class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        
        int n=dimensions.size();
        int maxDiagonalLength=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int diagonalLength=pow(dimensions[i][0],2)+pow(dimensions[i][1],2);
            cout<<diagonalLength<<" ";
             if(diagonalLength>=maxDiagonalLength)
             {
                if(diagonalLength==maxDiagonalLength)
                ans=max(dimensions[i][0]*dimensions[i][1],ans);
                else ans=dimensions[i][0]*dimensions[i][1];
                maxDiagonalLength=diagonalLength;
             }
        }
        return ans;
    }
};