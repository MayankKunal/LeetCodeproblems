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
        int prev2=1;
     int prev1=1;
        for(int i=2;i<=n;i++)
        {
           int curr=prev1+prev2;
           prev2=prev1;
           prev1=curr;
        }
        return prev1;
        
        
    }
};