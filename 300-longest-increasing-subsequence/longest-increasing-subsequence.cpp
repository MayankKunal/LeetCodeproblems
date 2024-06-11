class Solution {
    int help(int idx,int n,int prev,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(idx>=n) return 0;
        
        if(dp[idx][prev+1]!=-1) return dp[idx][prev+1];
        int notTake=help(idx+1,n,prev,nums,dp);
        int take=0;
        if(prev==-1 || nums[prev]<nums[idx])
        {
            take=1+help(idx+1,n,idx,nums,dp);
        }

        return dp[idx][prev+1]=max(take,notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return help(0,n,-1,nums,dp);
    }
};