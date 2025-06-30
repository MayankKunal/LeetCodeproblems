class Solution {
public:
    int findLHS(vector<int>& nums) {
        
    int n=nums.size();
    map<int,int>mp;
    for(int x:nums)
    {
        mp[x]++;
    }
sort(nums.begin(),nums.end());
int ans=0;
int len=0;
    for(int i=1;i<n;i++)
    {
            if(abs(nums[i]-nums[i-1])==1)
            {
               len=mp[nums[i]]+mp[nums[i-1]];
            }
            ans=max(ans,len);
    }

    return ans;
    }
};