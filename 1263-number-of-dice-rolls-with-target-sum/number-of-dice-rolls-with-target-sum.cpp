class Solution {
    int mod=(int) 1e9+7;
    int help(int i,int n,int k,int sum,int target,vector<vector<int>>&dp)
    {
        if(i==n)
        {
            return sum==target;
        }
        if(sum>target) return 0;
          if(dp[i][sum]!=-1) return dp[i][sum];
          int ans=0;
        for(int j=1;j<=k;j++)
        {
            ans=(ans+help(i+1,n,k,sum+j,target,dp)%mod)%mod;
        }
         return dp[i][sum]=ans;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        
         vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return help(0,n,k,0,target,dp);
    }
};