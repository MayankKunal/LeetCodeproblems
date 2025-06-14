class Solution {
    bool help(int i,int n,string s,unordered_set<string>&st,vector<int>&dp)
    {
        if(i==n)
        {
            return true;
        }
        if(dp[i]!=-1) return dp[i];
        for(int idx=i;idx<n;idx++)
        {
            string temp=s.substr(i,idx-i+1);
            if(st.find(temp)!=st.end())
            {
                if(help(idx+1,n,s,st,dp))
                return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string>st;
        vector<int>dp(n+1,-1);
        for(string word:wordDict)
        {
            st.insert(word);
        }
        return help(0,n,s,st,dp);
    }
};