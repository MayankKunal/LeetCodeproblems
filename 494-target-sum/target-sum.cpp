class Solution {
    int help(int i,int n,vector<int>&nums,int target)
    {
        if(i==n)
        {
            if(target==0) return 1;
            return 0;
        }
        return help(i+1,n,nums,target-nums[i])+help(i+1,n,nums,target+nums[i]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n=nums.size();
        return help(0,n,nums,target);
    }
};