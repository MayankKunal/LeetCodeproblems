class Solution {
    int bs(vector<vector<int>>&events,int end)
    {
        int n=events.size();
        int l=0,r=n-1;
        int idx=n;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(events[mid][0]>end)
            {
                idx=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return idx;
    }


    int help(int idx,int n,int count,vector<vector<int>>&events,vector<vector<int>>&dp)
    {
      if(idx>=n || count==2) return 0;
      if(dp[idx][count]!=-1) return dp[idx][count];
      int nextValidIndex=bs(events,events[idx][1]);
      int take=events[idx][2]+help(nextValidIndex,n,count+1,events,dp);
      int notTake=help(idx+1,n,count,events,dp);
      return dp[idx][count]=max(take,notTake);
    }


public:
    int maxTwoEvents(vector<vector<int>>& events) {
        
        int n=events.size();
        sort(events.begin(),events.end());
        vector<vector<int>>dp(n+1,vector<int>(3,-1));

        return help(0,n,0,events,dp);
    }
};