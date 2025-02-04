class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int n=nums.size();
        int sum=nums[0];
        int currEle=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]>currEle)
            {
                sum+=nums[i];
                
            }
            else
            {
                sum=nums[i];
                
            }
            currEle=nums[i];
            ans=max(ans,sum);
        }
        return ans;
    }
};