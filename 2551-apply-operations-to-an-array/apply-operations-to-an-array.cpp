class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n=nums.size();
          vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                if(i<n-1 && nums[i]==nums[i+1])
                {
                    nums[i]=nums[i]*2;
                    nums[i+1]=0;
                }
                ans.push_back(nums[i]);
            }
        }
        int m=ans.size();
        while(m<n)
        {
            ans.push_back(0);
            m++;
        }
        return ans;
    }
};