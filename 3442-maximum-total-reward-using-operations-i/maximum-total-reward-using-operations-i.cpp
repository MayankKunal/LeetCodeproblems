class Solution {
    int help(int i,int n,int sum,vector<int>&arr,vector<vector<int>>&dp)
    {
        if(i==n) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int notTake=help(i+1,n,sum,arr,dp);
        int take=0;
         if(sum<arr[i])
         {
            take=arr[i]+help(i+1,n,sum+arr[i],arr,dp);
         }
        return dp[i][sum]=max(take,notTake);
    }
public:
    int maxTotalReward(vector<int>& rewardValues) {
        
        int sum=0;
        for(int x:rewardValues) sum+=x;
        sort(rewardValues.begin(),rewardValues.end());
        int n=rewardValues.size();
        vector<vector<int>>dp(n+1,vector<int>(4001,-1));
        return help(0,n,0,rewardValues,dp);
    }
};