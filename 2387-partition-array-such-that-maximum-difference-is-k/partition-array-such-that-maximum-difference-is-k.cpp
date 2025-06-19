class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());

        int n=nums.size();
        int ans=1;
        int minEle=nums[0];
        for(int i=1;i<n;i++)
        {
            if(abs(nums[i]-minEle)>k)
            {
                minEle=nums[i];
                ans++;
            }
        }

        return ans;
    }
};