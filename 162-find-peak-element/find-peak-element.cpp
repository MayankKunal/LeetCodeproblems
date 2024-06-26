class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        int n=nums.size();
        int l=0,r=n-1;
        while(l<r)
        {
            int mid=(l+r)/2;
            if(mid==0) return nums[0]>=nums[1] ?0:1;
            if(mid==n-1) return nums[n-1]>=nums[n-2]?n-1:n-2;
            if(nums[mid]>=nums[mid-1] && nums[mid]>=nums[mid+1]) return mid;
            if(nums[mid]<nums[mid-1]) r=mid-1;
            else l=mid+1;
        }
        return l;
    }
};