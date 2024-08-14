class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {

       int maxEle=*max_element(nums.begin(),nums.end());
       vector<int>dp(maxEle+1,0);
       int n=nums.size();
       for(int i=0;i<n;i++)
       {
        for(int j=i+1;j<n;j++)
        {
              int dis=abs(nums[j]-nums[i]);
              dp[dis]++;
        }
       } 
       for(int i=0;i<maxEle+1;i++)
       {
          k-=dp[i];
          if(k<=0) return i;
       }
       return -1;
    }
};