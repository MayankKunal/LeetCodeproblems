class Solution {
public:
    int maximumLength(vector<int>& nums) {
        
        int evenParity=0,oddParity=0,altParity=1;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0) evenParity++;
            else oddParity++;
        }
int parity=nums[0]%2;
        for(int i=1;i<n;i++)
        {
              int currParity=nums[i]%2;
              if(currParity!=parity)
              {
                altParity++;
                parity=currParity;
              }
        }

        return max({evenParity,oddParity,altParity});
    }
};