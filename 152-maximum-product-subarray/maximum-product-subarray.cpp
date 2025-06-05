class Solution {
    int help(int i,int n,vector<int>&nums,vector<int>&dp)
    {
        if(i==n) return 1;
        if(dp[i]!=-1) return dp[i];
        
        int take=nums[i]*help(i+1,n,nums,dp);
        int notTake=help(i+1,n,nums,dp);

        return dp[i]=max(take,notTake);

    }
public:
    int maxProduct(vector<int>& nums) {
      int n=nums.size();
      int maxProduct=0;
      for(int i=0;i<n;i++)
      {
        int product=1;
        for(int j=i;j<n;j++)
        {
               product*=nums[j];
               maxProduct=max(maxProduct,product);
        }
      }
if(n==1) return nums[0];
      return maxProduct;
    }
};