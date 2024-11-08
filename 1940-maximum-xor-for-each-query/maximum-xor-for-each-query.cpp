class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        
        int high=pow(2,maximumBit)-1;
        int xorr=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            xorr^=nums[i];
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i]=xorr^high;
            xorr^=nums[n-i-1];
        }
        return ans;
    }
};