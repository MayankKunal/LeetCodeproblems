class Solution {
public:
  int help(int n,vector<int>&dp)
  {
    if(n==0) return 1;
    if(n<0) return 0;

    if(dp[n]!=-1) return dp[n];
    
    return dp[n]=help(n-1,dp)+help(n-2,dp);
  }
   int topDown(int n)
   {
    vector<int>dp(n+1,1);
       for(int i=2;i<=n;i++)
       {
        dp[i]=dp[i-1]+dp[i-2];
       }
       return dp[n];
   }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        // return help(n,dp);
        return topDown(n);
    }
};