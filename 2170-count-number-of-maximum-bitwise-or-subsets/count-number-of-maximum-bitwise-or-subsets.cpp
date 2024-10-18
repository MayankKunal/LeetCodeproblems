class Solution {
    void help(int idx,int n,vector<int>&nums,int currXor,int &maxXor,int &count)
    {
        if(idx==n)
        {
            if(currXor==maxXor)
            {
                count+=1;
            }
            return;
        }
        if(currXor>maxXor) return;
        help(idx+1,n,nums,currXor|nums[idx],maxXor,count);
        help(idx+1,n,nums,currXor,maxXor,count);
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        
        int maxXor=0;
        for(auto x:nums)
        {
            maxXor|=x;
        }
        cout<<maxXor;
int count=0;
        help(0,nums.size(),nums,0,maxXor,count);
        return count;
    }
};