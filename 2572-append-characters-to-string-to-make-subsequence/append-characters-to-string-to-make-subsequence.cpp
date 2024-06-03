class Solution {
#define ll long long
    ll help(ll i,ll j,ll n,ll m,string s,string t,vector<vector<ll>>&dp)
    {
        if(j==m) return 0;
        if(i==n) return m-j;
       if(dp[i][j]!=-1) return dp[i][j];

        if(s[i]==t[j])
        {
            return dp[i][j]=help(i+1,j+1,n,m,s,t,dp);
        }
     return dp[i][j]=help(i+1,j,n,m,s,t,dp);

    }
public:
    int appendCharacters(string s, string t) {
        int n=s.size();
    int m=t.size();
    int idx=0;
    int ans=0;
      for(int i=0;i<n;i++)
      {
        if(s[i]==t[idx]){
              idx++;
        }
      }
      return m-idx;  
    }
};