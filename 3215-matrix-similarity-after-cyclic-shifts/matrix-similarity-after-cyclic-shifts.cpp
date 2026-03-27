class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        
        int n=mat.size();
        int m=mat[0].size();
     vector<vector<int>>originalMat=mat;
     while(k--)
     {
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                int val=mat[i][0];
            for(int j=0;j<m-1;j++)
            {
                mat[i][j]=mat[i][j+1];
            }
            mat[i][m-1]=val;
            }
            else
            {
                int val=mat[i][m-1];
                for(int j=m-1;j>0;j--)
                {
                    mat[i][j]=mat[i][j-1];
                }
                mat[i][0]=val;
            }
        }
     }

      return mat==originalMat;
    }
};