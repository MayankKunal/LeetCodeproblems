class Solution {
    void help(int idx,int n,vector<int>&nums,int tempXor,int &finalXor)
    {
        if(idx==n)
        {
            finalXor+=tempXor;
            return;
        }

        help(idx+1,n,nums,tempXor^nums[idx],finalXor);
        help(idx+1,n,nums,tempXor,finalXor);
    }
public:
    int subsetXORSum(vector<int>& nums) {

     int n=nums.size();

     int finalXor=0;

     help(0,n,nums,0,finalXor);
  return finalXor;
    }
};