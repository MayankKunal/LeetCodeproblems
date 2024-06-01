class Solution {
    int firstOccurance(vector<int>& nums, int x)
    {
        int n=nums.size();
        int l=0,r=n-1;
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]>=x)
            {
                if(nums[mid]==x) ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
    int lastOccurance(vector<int>& nums, int x)
    {
        int n=nums.size();
        int l=0,r=n-1;
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]<=x)
            {
                if(nums[mid]==x) ans=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        return {firstOccurance(nums,target),lastOccurance(nums,target)};

    }
};