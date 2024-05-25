class Solution {
    int help(int idx,int n,string s,unordered_set<string>&st,vector<int>&dp)
    {
        if(idx==n) return 1;
        if(dp[idx]!=-1) return dp[idx];
        string temp="";
        for(int j=idx;j<n;j++)
        {
            temp+=s[j];
            if(st.find(temp)!=st.end())
            {
                if(help(j+1,n,s,st,dp)) return dp[idx]=1;
            }
        }
        return dp[idx]=0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st;
        st.insert(wordDict.begin(),wordDict.end());
        vector<int>dp(s.size()+1,-1);
        return help(0,s.size(),s,st,dp);
    }
};