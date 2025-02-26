class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int n=nums.size();
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum<0)sum=0;
            ans=max(ans,sum);
        }
        sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum>0) sum=0;
            ans=max(ans,abs(sum));
        }
        return ans;
    }
};