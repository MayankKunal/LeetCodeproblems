class Solution {
    void help(int idx,int n,vector<int>&nums,int temp,int &sum)
    {
        if(idx==n)
        {
            sum+=temp;
            return;
        }

        help(idx+1,n,nums,temp^nums[idx],sum);
        help(idx+1,n,nums,temp,sum);

    }
public:
    int subsetXORSum(vector<int>& nums) {
        
        int sum=0;
        int n=nums.size();
        help(0,n,nums,0,sum);
        return sum;
    }
};