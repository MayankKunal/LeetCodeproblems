class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int minDiff=INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            int l=i+1,r=n-1;
            while(l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];
                int diff=abs(sum-target);
                if(diff<minDiff)
                {
                    minDiff=diff;
                    ans=sum;
                }
                else if(sum>target) r--;
                else l++;
            }
        }
        return ans;
    }
};