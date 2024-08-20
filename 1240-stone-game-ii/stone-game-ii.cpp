class Solution {
    int help(int turn,int idx,int n,vector<int>&piles,int dp[][101][101],int M)
    {
        if(idx>=n) return 0;
        if(dp[turn][idx][M]!=-1) return dp[turn][idx][M];
        int stones=0;
        int result;
        if(turn==0) result=-1;
        else result=INT_MAX;
        if(turn==0)
        {
        for(int x=1;x<=min(2*M,n-idx);x++)
        {
            stones+=piles[idx+x-1];
            result=max(result,stones+help(1,idx+x,n,piles,dp,max(M,x)));
        }

        }
        else
        {
            for(int x=1;x<=min(2*M,n-idx);x++)
            result=min(result,help(0,idx+x,n,piles,dp,max(M,x)));
        }

        return dp[turn][idx][M]=result;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        int dp[2][101][101];
        memset(dp,-1,sizeof(dp));
        return help(0,0,n,piles,dp,1);
    }
};