class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n=nums.size();
        int l=0,r=0;
        unordered_map<int,int>mp;
        int sum=0,ans=0;
        while(r<n)
        {
        
           while(mp.find(nums[r])!=mp.end())
           {
              mp[nums[l]]--;
              sum-=nums[l];
              if(mp[nums[l]]==0) mp.erase(nums[l]);
              l++;
           }
           mp[nums[r]]++;
           sum+=nums[r];
           ans=max(ans,sum);
           r++;
        }

        return ans;
    }
};