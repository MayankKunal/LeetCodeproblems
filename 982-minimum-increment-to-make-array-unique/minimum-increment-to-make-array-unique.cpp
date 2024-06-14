class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        for(int i=1;i<n;i++)
        {
              if(nums[i]<=nums[i-1])
              {
                int diff=nums[i-1]-nums[i];
                cout<<diff;
                nums[i]=nums[i]+diff+1;
                count+=diff+1;
              }
        }
        return count;
    }
};