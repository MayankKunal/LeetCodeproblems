class Solution {
   int help(vector<int>&nums,int k)
   {
      int left=0,right=0;
      int count=0;
      int n=nums.size();
      int maxCount=0;
      while(right<n)
      {
        if(nums[right]%2==1) count++;
        while(count>k)
        {
            if(nums[left]%2==1) count--;
            left++;
        }
        maxCount+=right-left+1;
        right++;
      }
      return maxCount;
   }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return help(nums,k)-help(nums,k-1);
    }
};