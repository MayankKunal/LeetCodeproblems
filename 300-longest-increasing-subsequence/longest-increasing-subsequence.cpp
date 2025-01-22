class Solution {
    int help(int i,int n,vector<int>&nums,int prev,vector<vector<int>>&dp)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take=0;
        if(prev==-1 || nums[prev]<nums[i])
        {
            take=1+help(i+1,n,nums,i,dp);
        }
        int 
        notTake=help(i+1,n,nums,prev,dp);

        return dp[i][prev+1]=max(take,notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        
        int n=nums.size();
 
        //  vector<vector<int>>dp1(n+1,vector<int>(n+2,-1));
        // return help(0,n,nums,-1,dp);
        int res=1;
        vector<int>ans(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                ans[i]=max(ans[i],ans[j]+1);
                res=max(res,ans[i]);
                }
            }
        }
        return res;
    }
};