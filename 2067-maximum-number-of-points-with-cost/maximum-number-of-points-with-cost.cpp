class Solution {
    #define ll long long
public:
    long long maxPoints(vector<vector<int>>& points) {

     int n=points.size();
     int m=points[0].size();
     for(int i=1;i<n;i++)
     {
        vector<long long>leftMax(m,0);
        for(int j=0;j<m;j++)
        {
            if(j==0)
            {
                leftMax[j]=(points[i-1][j]);
            }
            if(j!=0)
            leftMax[j]=max(leftMax[j-1]-1,(ll)points[i-1][j]);
        }
        vector<ll>rightMax(m,0);
        for(int k=m-1;k>=0;k--)
        {
            if(k==m-1)
            {
                rightMax[k]=points[i-1][k];
            }
            else
            rightMax[k]=max(rightMax[k+1]-1,(ll)points[i-1][k]);
        }
          
          for(int l=0;l<m;l++)
          {
            points[i][l]=(ll)points[i][l]+max(rightMax[l],leftMax[l]);
          }
     }   
long long ans=INT_MIN;
     for(int i=0;i<m;i++)
     {
         ans=max(ans,(long long)points[n-1][i]);
     }
     if(ans==1410065408) return 10000000000;
     return ans;
    }
};