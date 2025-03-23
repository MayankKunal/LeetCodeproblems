class Solution {
    int help(int idx,int n, string&digits,vector<int>&dp)
    {
        // if(idx==n-1){
        //     if(digits[idx]!='0') return 1;
        //     return 0;
        // }
        if(idx==n) return 1;
        if(digits[idx]=='0') return 0;
        if(dp[idx]!=-1) return dp[idx];
         int oneDigit=help(idx+1,n,digits,dp);
         int twoDigit=0;
        if((idx+1)<n)
        {
         char val1=digits[idx];
         char val2=digits[idx+1];
         if ((val1 == '1') || (val1 == '2' && val2 <= '6'))
         twoDigit=help(idx+2,n,digits,dp);
        }
         return dp[idx]=oneDigit+twoDigit;
    }
public:
    int numDecodings(string s) {
        
        int n=s.size();
        vector<int>dp(n+1,-1);
        return help(0,n,s,dp);
    }
};