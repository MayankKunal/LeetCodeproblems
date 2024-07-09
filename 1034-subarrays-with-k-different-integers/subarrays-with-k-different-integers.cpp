class Solution {
    int help(vector<int>&nums,int k)
    {
        // if(k<=0) return 0;
        unordered_map<int,int>mp;
        int l=0,r=0;
        int n=nums.size();
        int ans=0;
        while(r<n)
        {
            mp[nums[r]]++;
            while(mp.size()>k)
            {
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                   mp.erase(nums[l]);
             l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return help(nums,k)-help(nums,k-1);
    }
};