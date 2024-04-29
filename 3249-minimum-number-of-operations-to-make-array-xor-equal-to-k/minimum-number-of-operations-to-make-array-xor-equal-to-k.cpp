class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int xorSum=0;
        for(int x:nums)
        {
            xorSum=xorSum^x;
        }
        xorSum^=k;
        int count=0;
        while(xorSum>0)
        {
            int dig=xorSum&1;
            if(dig) count++;
            xorSum=xorSum>>1;
        }
        return count;
    }
};