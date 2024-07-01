class Solution {
    #define ll long long
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        int l,r;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<n;j++)
            {
               if(j>i+1 && nums[j]==nums[j-1]) continue;
              l=j+1,r=n-1;
              while(l<r)
              {  ll sum=nums[i];
              sum+=nums[j];
              sum+=nums[l];
              sum+=nums[r];
                  if(sum<target) l++;
                  else if(sum>target) r--;
                  else
                  {
                    ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1])l++;
                    while(l<r && nums[r]==nums[r+1])r--;
                  }
              }

            }
        }
        return ans;
    }
};