class Solution {
    // bool help(int i,int n,int targetSum,vector<int>&nums,vector<vector<int>>&dp)
    // {
    //     if(i==n)
    //     {
    //         if(targetSum==0) return true;
    //         return false;
    //     }
    //     if(targetSum<0) return false;
    //     if(dp[i][targetSum]!=-1) return dp[i][targetSum];
    //      bool take=help(i+1,n,targetSum-nums[i],nums,dp);
    //      bool notTake=help(i+1,n,targetSum,nums,dp);
    //      return dp[i][targetSum]=take||notTake;
    // }
public:
    bool canPartition(vector<int>& nums) {
        
        int n=nums.size();
    int sum=0;
        for(int x:nums)
        {
            sum+=x;
        }
        if(sum%2==1) return false;
        int targetSum=sum/2;
        vector<vector<bool>>dp(n+1,vector<bool>(targetSum+1,false));
        for(int i=0;i<n;i++)
        {
            dp[i][0]=true;
        }
        for(int i=1;i<n;i++)
        {
               for(int j=0;j<=targetSum;j++)
               {
                bool take=false;
                if(j>=nums[i])
                  take=dp[i-1][j-nums[i]];
                  bool notTake=dp[i-1][j];

                  dp[i][j]=take||notTake;
               }
        }

        return dp[n-1][targetSum];

    }
};