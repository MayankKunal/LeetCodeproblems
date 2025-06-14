class Solution {
    int help(int i,int n,vector<int>&coins,int amount,vector<vector<int>>&dp)
    {
        if(i==n)
        {
            if(amount==0) return 0;
            return (int) 1e8+7;
        }

        if(dp[i][amount]!=-1) return dp[i][amount];

        int take=(int)1e8+7;
        if(amount>=coins[i])
        {
            take=1+help(i,n,coins,amount-coins[i],dp);
        }
        int notTake=help(i+1,n,coins,amount,dp);


        return dp[i][amount]=min(take,notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));


        int ans=help(0,n,coins,amount,dp);
        if(ans==(int)1e8+7) return -1;
        return ans;
    }
};