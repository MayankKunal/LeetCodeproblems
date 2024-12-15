class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        
        int l=0,r=0;
        int n=nums.size();
        long long ans=0;
        map<int,int>mp;
        while(r<n)
        {
           mp[nums[r]]++;
           while((mp.rbegin()->first-mp.begin()->first)>2)
           {
              mp[nums[l]]--;
              if(mp[nums[l]]==0) mp.erase(nums[l]);
              l++;
           }
           ans+=(r-l+1);
           r++;
        }
        return ans;
    }
};