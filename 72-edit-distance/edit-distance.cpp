class Solution {
    int help(int i,int j,int n,int m,string &word1,string &word2,vector<vector<int>>&dp)
    {
        if(i==n)
        {
            return m-(j);
        }
        if(j==m)
        {
            return n-(i);
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int take=INT_MAX;
        if(word1[i]==word2[j])
        {
          take=help(i+1,j+1,n,m,word1,word2,dp);
        }
        int notTake=1+min(help(i+1,j,n,m,word1,word2,dp),min(help(i,j+1,n,m,word1,word2,dp),help(i+1,j+1,n,m,word1,word2,dp)));
         
         return dp[i][j]=min(take,notTake);
    }
public:
    int minDistance(string word1, string word2) {
        
        int n=word1.size();
        int m=word2.size();
       vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return help(0,0,n,m,word1,word2,dp);
    }
};