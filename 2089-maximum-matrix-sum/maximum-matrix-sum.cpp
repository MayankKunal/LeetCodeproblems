class Solution {
#define ll long long
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        
       ll n=matrix.size();
       ll m=matrix[0].size();
     ll count=0;
     ll sum=0;
     ll minEle=INT_MAX;
       for(int i=0;i<n;i++)
       {
         for(int j=0;j<m;j++)
         {
            sum+=abs(matrix[i][j]);
        
            minEle=min(minEle,(ll)abs(matrix[i][j]));
            if(matrix[i][j]<0) count++;
         }
       }
       if(count%2==0) return sum;
       return sum-2*(abs(minEle));
    }
};