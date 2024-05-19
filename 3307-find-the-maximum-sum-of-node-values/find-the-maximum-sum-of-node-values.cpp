
class Solution {
    typedef long long  ll;
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
     ll sum=0;
     ll count=0;
     ll minLoss=INT_MAX;
     for(int i=0;i<nums.size();i++)
     {
        if(nums[i]<(nums[i]^k))
        {
            count++;
            sum+=nums[i]^k;
        }
        else
        {
            sum+=nums[i];
        }

        if(abs(nums[i]-(nums[i]^k))<minLoss)
        minLoss=abs(nums[i]-(nums[i]^k));
     }
     if(count%2==0) return sum;

     return sum-minLoss;
    }
};