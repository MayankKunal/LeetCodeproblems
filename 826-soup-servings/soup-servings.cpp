class Solution {
    vector<vector<int>>ser={{100,0,},{75,25},{50,50},{25,75}};
    double help(int a,int b,vector<vector<double>>&dp)
    {
        if(a<=0 && b<=0) return 0.5;
        if(a<=0 && b>0) return 1.0;
        if(a>0 && b<=0) return 0.0;

        if(dp[a][b]!=-1.0) return dp[a][b];
        double total=0.0;
        for(auto s:ser)
        {
            int x=a-s[0];
            int y=b-s[1];
            total+=help(x,y,dp);
        }

        return dp[a][b]=total/4;
    }
public:
    double soupServings(int n) {
        
        if(n>=5000) return 1;
        vector<vector<double>>dp(n+1,vector<double>(n+1,-1.0));
        return help(n,n,dp);
    }
};