class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long n=nums.size();
        long long ans=0;
        unordered_map<long long ,long long>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i]-i)!=mp.end())
            {
                ans+=mp[nums[i]-i];
            }
            mp[nums[i]-i]++;
        }
        cout<<ans;
        long long totalPair=((n)*(n-1))/2;
        return totalPair-ans;
    }
};