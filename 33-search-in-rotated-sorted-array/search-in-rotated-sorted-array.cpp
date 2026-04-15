class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int n=nums.size();

        int l=0,r=n-1;
        while(l<=r)
        {
            int mid=(l+r)/2;

            if(nums[mid]==target) return mid;

            if(nums[l]<=nums[mid])
            {
                if(target>=nums[l] && target<nums[mid]) r--;
                else
                l++;
            }
            else
            {
                if(target>nums[mid] && target<=nums[r]) l++;
                else
                 r--;
            }
        }

        return -1;
    }
};