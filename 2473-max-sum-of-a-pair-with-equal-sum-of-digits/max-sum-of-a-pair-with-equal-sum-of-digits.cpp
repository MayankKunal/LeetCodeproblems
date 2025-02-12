class Solution {
    int findSum(int n)
    {
        int sum=0;
        while(n>0)
        {
            int d=n%10;
            sum+=d;
            n/=10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        
        int n=nums.size();
        unordered_map<int,int>mp;
        int maxSum=-1;
            for(int i=0;i<n;i++)
            {
                int sum=findSum(nums[i]);
              if(mp.find(sum)!=mp.end())
              {
                maxSum=max(maxSum,mp[sum]+nums[i]);
                if(mp[sum]<nums[i])
                {
                    mp[sum]=nums[i];
                }
              }
              else
              mp[sum]=nums[i];
            }
            
            return maxSum;
    }

};