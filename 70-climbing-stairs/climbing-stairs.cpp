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
        vector<int>dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
          dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
        
        
    }
};