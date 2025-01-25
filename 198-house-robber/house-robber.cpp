class Solution {
    int topDown(int i,int n,vector<int>&nums,vector<int>&dp)
    {
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int take=nums[i]+topDown(i+2,n,nums,dp);
        int notTake=topDown(i+1,n,nums,dp);
        return dp[i]=max(take,notTake);
    }
    int bottomUp(vector<int>&nums)
    {
        int n=nums.size();
        vector<int>dp(n+1,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
             int take=nums[i];
             if(i>1)
             take+=dp[i-2];
        int notTake=dp[i-1];
        dp[i]=max(take,notTake);
        }
        return dp[n-1];
    }
public:
    int rob(vector<int>& nums) {

     int n=nums.size();
    //  vector<int>dp(n,-1);
    //  return topDown(0,n,nums,dp);   
    return bottomUp(nums);
    }
};