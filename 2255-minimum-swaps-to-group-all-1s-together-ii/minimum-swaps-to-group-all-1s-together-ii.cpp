class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        int n=nums.size();
        int count=0;
        for(int x:nums)
        {
            if(x==1) count++;
        }
        nums.insert(nums.end(),nums.begin(),nums.end());
        int swaps=0;
        for(int i=0;i<count;i++)
        {
            if(nums[i]==0) swaps++;
        }
        int minSwap=swaps;
        for(int i=count;i<2*n;i++)
        {
            if(nums[i]==0) swaps++;
            if(nums[i-count]==0) swaps--;
            minSwap=min(minSwap,swaps);
        }
        return minSwap;
    }
};