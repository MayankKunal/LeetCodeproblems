class Solution {

    int help(int i,int n,int prev,vector<int>&nums,vector<vector<int>>&dp)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take=0;
        if(prev==-1 || nums[i]>nums[prev])
        {
            take=1+help(i+1,n,i,nums,dp);
        }

        int notTake=help(i+1,n,prev,nums,dp);


        return dp[i][prev+1]=max(take,notTake);

    }
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();

        vector<vector<int>>dp(n+1,vector<int>(n+2,-1));

        return help(0,n,-1,nums,dp);
    }
};