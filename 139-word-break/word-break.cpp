class Solution {
   bool help(int i,int n,string s,unordered_map<string,int>&wordDict,vector<int>&dp)
    {
        if(i==n)
        {
           return true;
        }
        if(dp[i]!=-1) return dp[i];
        for(int idx=i;idx<n;idx++)
        {
            if(wordDict.find(s.substr(i,idx-i+1))!=wordDict.end())
            {
                 if(help(idx+1,n,s,wordDict,dp)) return dp[i]=true;
            }   
        }

        return dp[i]=false;
         
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string,int>mp;
        for(auto x:wordDict)
        {
            mp[x]++;
        }
        int n=s.size();
        vector<int>dp(n+1,-1);
        return help(0,s.size(),s,mp,dp);
       
    }
};