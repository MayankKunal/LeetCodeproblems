class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int n=nums.size();
        int currEle=nums[0];
        int count=1;
        int maxCount=1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>currEle)
            {
                count++;
            } 
            else
            {
                 count=1;
            }
            maxCount=max(maxCount,count);
            currEle=nums[i];
        }
      count=1;
      currEle=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]<currEle)
            {
                count++;
            } 
            else
            {
                 count=1;
            }
            maxCount=max(maxCount,count);
            currEle=nums[i];
        }

        return maxCount;

    }
};