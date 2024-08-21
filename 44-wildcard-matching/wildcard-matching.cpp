class Solution {
    int help(int n,int m,string s,string p,vector<vector<int>>&dp)
    {
        if(m==0)
        {
            if(n==0) return 1;
            return 0;
        }
        if(n==0)
        {
            if(m==0) return true;
            else 
            {
                for(int i=m-1;i>=0;i--)
                {
                    if(p[i]!='*') return dp[n][i]=false;
                }
                return dp[n][0]=true;
            }
            return false;
        }

        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n-1]==p[m-1] || p[m-1]=='?')
        {
            return dp[n][m]=help(n-1,m-1,s,p,dp);
        }
        if(p[m-1]=='*')
        {
            return dp[n][m]=help(n-1,m,s,p,dp)|help(n,m-1,s,p,dp);
        }
        else
        {
            return dp[n][m]=false;
        }
    }
public:
    bool isMatch(string s, string p) {
        
        int n=s.size();
        int m=p.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return help(n,m,s,p,dp);
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int i=1;i<=m;i++)
        {
            bool flag=1;
            for(int j=0;j<i;j++)
            {
                if(p[j]!='*')
                {
                     flag=0;
                     break;
                }

            }
            dp[0][i]=flag;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==p[j-1] || p[j-1]=='?')
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else if(p[j-1]=='*')
                {
                  dp[i][j]=dp[i-1][j]|dp[i][j-1];
                }
                else if(s[i-1]!=p[j-1])
                {
                    dp[i][j]=0;
                }
            }
        }
        return dp[n][m];
    }
};