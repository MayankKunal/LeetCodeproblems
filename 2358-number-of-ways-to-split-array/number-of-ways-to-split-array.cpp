class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        int n=nums.size();
        vector<long long>prefixSum(n,0);
        prefixSum[0]=nums[0];
        long long sum=nums[0];
        for(int i=1;i<n;i++)
        {
            sum+=nums[i];
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }
          int count=0;
        for(int i=0;i<n-1;i++)
        {
            if(2*prefixSum[i]>=sum)
            count++;
        }
        return count;
    }
};