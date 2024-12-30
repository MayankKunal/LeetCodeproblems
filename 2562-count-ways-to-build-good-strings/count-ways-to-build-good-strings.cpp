class Solution {
    int mod=1e9+7;
    long long help(int total,int stp1,int stp2,vector<int>&dp)
    {
        if(total==0) return 1;
        if(total<0) return 0;
        if(dp[total]!=-1) return dp[total];
        return dp[total]=(help(total-stp1,stp1,stp2,dp)%mod+help(total-stp2,stp1,stp2,dp)%mod)%mod;
    }
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        
        int ans=0;
        vector<int>dp(high+1,-1);
        for(int len=low;len<=high;len++)
        {
            
            ans=(ans+(help(len,zero,one,dp))%mod)%mod;
        }
        return ans;
    }
};