class Solution {
    int help(int idx,int n,vector<int>&coins,int amount,vector<vector<int>>&dp)
    {
        if(idx==n)
        {
            if(amount==0) return 0;
            return INT_MAX-1;
        }
        if(dp[idx][amount]!=-1) return dp[idx][amount];
        if(coins[idx]<=amount)
        {
            return dp[idx][amount]=min(1+help(idx,n,coins,amount-coins[idx],dp),help(idx+1,n,coins,amount,dp));
        }
        return dp[idx][amount]=help(idx+1,n,coins,amount,dp);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
int n=coins.size();
     vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
     int ans=help(0,n,coins,amount,dp);
     if(ans==2147483646) return -1;
     return ans;   
    }
};