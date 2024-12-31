class Solution {
    int help(int i,int n,vector<int>&days,vector<int>&costs,vector<int>&dp)
    {
        if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
        int ans=INT_MAX;
        ans = costs[0] + help(i + 1, n, days, costs,dp);

        // 7-day pass: Find the next day outside the validity of this pass.
        int j = i;
        while (j < n && days[j] < days[i] + 7) j++;
        ans = min(ans, costs[1] + help(j, n, days, costs,dp));

        // 30-day pass: Find the next day outside the validity of this pass.
        j = i;
        while (j < n && days[j] < days[i] + 30) j++;
        ans = min(ans, costs[2] + help(j, n, days, costs,dp));
        return dp[i]=ans;
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int n=days.size();
        vector<int>dp(n+1,-1);
       return help(0,n,days,costs,dp);
    }
};