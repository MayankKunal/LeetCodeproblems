class Solution {
    bool help(int i,int n,vector<int>&nums,int sum,vector<vector<int>>&dp)
    {
        if(i==n)
        {
            if(sum!=0) return 0;
            return 1;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];

        int take=0;
        if(sum>=nums[i])
        {
            take=take||help(i+1,n,nums,sum-nums[i],dp);
        }
        int notTake=0;
         notTake=notTake||help(i+1,n,nums,sum,dp);
            return dp[i][sum]=take||notTake;
    }
public:
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        int n=nums.size();
        for(int x:nums)
        {
            sum+=x;
        }
        if(sum%2==1) return false;
      int targetSum=sum/2;
        vector<vector<int>>dp(n+1,vector<int>(targetSum+1,-1));

        return help(0,n,nums,targetSum,dp);
    }
};