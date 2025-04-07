class Solution {
    int help(int idx,int n,int sum,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(sum==0) return 1;
        if(idx==n)
        {
            if(sum==0) return 1;
            return 0;
        }
        if(sum<0) return 0;
        if(dp[idx][sum]!=-1) return dp[idx][sum];

        return dp[idx][sum]=help(idx+1,n,sum-nums[idx],nums,dp)|help(idx+1,n,sum,nums,dp);
    }
public:
    bool canPartition(vector<int>& nums) {
        
        int n=nums.size();
        int sum=0;
         for(auto x:nums)
         {
          sum+=x;
         }

        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        if(sum%2!=0) return false;
        sum/=2;
        return help(0,n,sum,nums,dp);

    }
};