class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int maxEle=0;
        for(int x:nums)
        {
            maxEle=max(maxEle,x);
        }
        int count=0;
        int n=nums.size();
        int ans=1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==maxEle) count++;
            else count=0;
            ans=max(ans,count);
        }
        return ans;
    }
};