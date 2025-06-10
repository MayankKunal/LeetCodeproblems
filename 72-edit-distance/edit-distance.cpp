class Solution {
    long long  help(int i,int j,int n,int m,string &word1,string &word2,vector<vector<long long>>&dp)
    {
        if(i==n || j==m) return max((n-i),(m-j));
          
          if(dp[i][j]!=-1) return dp[i][j];

          long long take=INT_MAX;
          if(word1[i]==word2[j])
          {
            take=help(i+1,j+1,n,m,word1,word2,dp);
          }
          long long notTake=1+min(help(i+1,j,n,m,word1,word2,dp),min(help(i,j+1,n,m,word1,word2,dp),help(i+1,j+1,n,m,word1,word2,dp)));

          return dp[i][j]=min(take,notTake);
    }
public:
    int minDistance(string word1, string word2) {

     int n=word1.size();
     int m=word2.size();
      
      vector<vector<long long>>dp(n+1,vector<long long>(m+1,-1));


      return help(0,0,n,m,word1,word2,dp);


    }
};