class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        vector<vector<int>>matrix(n,vector<int>(n,1e9));
          for(auto x:edges)
          {
              matrix[x[0]][x[1]]=x[2];
              matrix[x[1]][x[0]]=x[2];
          }
         
         for(int k=0;k<n;k++)
         {   matrix[k][k]=0;
          for(int i=0;i<n;i++)
          {
              for(int j=0;j<n;j++)
              {

                  

                   matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);

                   
              }
          }
         }
 int ans = -1;
int mincount = n;  // Initialize maxcount with INT_MAX
for (int i = 0; i < n; i++) {
    int count = 0;
    for (int j = 0; j < n; j++) {
        if (matrix[i][j] <= distanceThreshold) {
            count++;
        }
    }
    if (count <= mincount) {
        mincount = count;
        ans = i;
    }
}


          return ans;
         
    }
};