class Solution {
    vector<int>dp;
    int help(int i,int n,vector<int>&nums)
    {
        if(i>=n) return 0;
         if(dp[i]!=-1) return dp[i];
         int take=nums[i]+help(i+2,n,nums);
         int notTake=help(i+1,n,nums);

         return dp[i]=max(take,notTake);
    }
public:
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        dp.resize(n+1,-1);
        return help(0,n,nums);
    }
};