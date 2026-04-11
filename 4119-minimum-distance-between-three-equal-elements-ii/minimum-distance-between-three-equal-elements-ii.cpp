class Solution {

    int help(vector<int>arr)
    {
        int n=arr.size();
        int ans=INT_MAX;
        for(int i=0;i<n-2;i++)
        {
            
                ans=min(ans,2*(arr[i+2]-arr[i]));
        }

        return ans;
    }
public:
    int minimumDistance(vector<int>& nums) {
        

        unordered_map<int,vector<int>>mp;

        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]].push_back(i);
        }
      int ans=INT_MAX;
        for(auto x:mp)
        {
            if(x.second.size()>=3)
            {
                ans=min(ans, help(x.second));
            }
        }
          if(ans==INT_MAX) return -1;
        return ans;
    }
};