class Solution {
     
    vector<int>dp;
public:
    int fib(int n) {
        
      dp.resize(n+1,-1);
        return help(n);
    }
    int help(int n)
    {
        if(n==0 || n==1) return n;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=help(n-1)+help(n-2);
    }
};