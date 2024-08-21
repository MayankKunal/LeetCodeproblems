class Solution {
    int help(int n,int m,string s1,string s2,vector<vector<int>>&dp)
    {
        if(n==0 || m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s1[n-1]==s2[m-1])
        {
            return dp[n][m]=1+help(n-1,m-1,s1,s2,dp);
        }
        return dp[n][m]=max(help(n-1,m,s1,s2,dp),help(n,m-1,s1,s2,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return help(n,m,text1,text2,dp);
        vector<vector<int>>dp2(n+1,vector<int>(m+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp2[i][j]=1+dp2[i-1][j-1];
                }
                else
                {
                    dp2[i][j]=max(dp2[i-1][j],dp2[i][j-1]);
                }
            }
        }
        return dp2[n][m];
    }
};