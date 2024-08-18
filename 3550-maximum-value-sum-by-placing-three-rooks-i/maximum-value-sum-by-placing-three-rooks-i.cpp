class Solution {
    long long help(int idx,int firstCol,int secondCol,int n,vector<vector<pair<long long,long long>>>&arr,vector<vector<vector<long long>>>&dp)
    {
        if(idx==n) return -1e11;
        if(dp[idx][firstCol+1][secondCol+1]!=-1) return dp[idx][firstCol+1][secondCol+1];
        long long ans=LONG_LONG_MIN;
        if(firstCol==-1)
        {
            ans=max(ans,help(idx+1,firstCol,secondCol,n,arr,dp));
            ans=max(ans,arr[idx][0].first+help(idx+1,arr[idx][0].second,secondCol,n,arr,dp));
            ans=max(ans,arr[idx][1].first+help(idx+1,arr[idx][1].second,secondCol,n,arr,dp));
            ans=max(ans,arr[idx][2].first+help(idx+1,arr[idx][2].second,secondCol,n,arr,dp));
        }
        else if(secondCol==-1)
        {
             ans=max(ans,help(idx+1,firstCol,secondCol,n,arr,dp));
             if(arr[idx][0].second!=firstCol)
            ans=max(ans,arr[idx][0].first+help(idx+1,firstCol,arr[idx][0].second,n,arr,dp));
            if(arr[idx][1].second!=firstCol)
            ans=max(ans,arr[idx][1].first+help(idx+1,firstCol,arr[idx][1].second,n,arr,dp));
            if(arr[idx][2].second!=firstCol)
            ans=max(ans,arr[idx][2].first+help(idx+1,firstCol,arr[idx][2].second,n,arr,dp));
        }
        else
        {
            ans=max(ans,help(idx+1,firstCol,secondCol,n,arr,dp));
             if(arr[idx][0].second!=firstCol && arr[idx][0].second!=secondCol)
            ans=max(ans,arr[idx][0].first);
            if(arr[idx][1].second!=firstCol &&arr[idx][1].second!=secondCol)
            ans=max(ans,arr[idx][1].first);
            if(arr[idx][2].second!=firstCol && arr[idx][2].second!=secondCol)
            ans=max(ans,arr[idx][2].first);
        }

        return dp[idx][firstCol+1][secondCol+1]=ans;
    }
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        
        int n=board.size();
        int m=board[0].size();
           vector<vector<pair<long long ,long long>>>arr;
           for(int i=0;i<n;i++)
           {
            vector<pair<long long,long long>>temp;
            for(int j=0;j<m;j++)
            {
                temp.push_back({board[i][j],j});
            }
            sort(temp.rbegin(),temp.rend());
           
            arr.push_back(temp);
           }
vector<vector<vector<long long>>>dp(n+1,vector<vector<long long>>(m+1,vector<long long>(m+1,-1)));
           return help(0,-1,-1,n,arr,dp);
    }
};