class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        int n=nums.size();
        vector<long long>leftMax(n,0),rightMax(n,0);
        for(int i=1;i<n;i++)
        {
          leftMax[i]=max(leftMax[i-1],(long long)nums[i-1]);
        }
        for(int i=n-2;i>=0;i--)
        {
            rightMax[i]=max(rightMax[i+1],(long long)nums[i+1]);
        }

       long long ans=0;
        for(int i=1;i<n-1;i++)
        {
            ans=max(ans,(leftMax[i]-(long long)nums[i])*rightMax[i]);
        }
        return ans;
    }
};