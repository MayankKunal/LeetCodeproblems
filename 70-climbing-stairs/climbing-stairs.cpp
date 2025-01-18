class Solution {
    int help(int idx,int n,vector<int>&dp)
    {
         if(idx>n) return 0;
         if(idx==n) return 1;
        if(dp[idx]!=-1) return dp[idx];
        return dp[idx]=help(idx+1,n,dp)+help(idx+2,n,dp);
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        
        return help(0,n,dp);
        
    }
};