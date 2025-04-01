class Solution {
    long long help(int i,int n,vector<vector<int>>&questions,vector<long long>&dp)
    {
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
         int points=questions[i][0];
         int next=questions[i][1];
        long long take=points+help(i+next+1,n,questions,dp);
        long long notTake=help(i+1,n,questions,dp);
        return dp[i]=max(take,notTake);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        
        int n=questions.size();

        vector<long long>dp(n+1,-1);

        return help(0,n,questions,dp);
    }
};