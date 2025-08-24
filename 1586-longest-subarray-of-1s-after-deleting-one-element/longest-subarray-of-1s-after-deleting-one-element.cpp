class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int n=nums.size();
        int count=0;
        int maxCount=0;
        int zeroCount=0;
        int idx=-1;
        for(int i=0;i<n;i++)
        {
           if(nums[i]==1)
           {
            count++;
           }
           else
           {
            if(zeroCount==0)
            {
                zeroCount=1;
                idx=i;
            }
            else
            {
                cout<<i<<"->"<<idx<<"->";
                
                count=max(0,i-idx-1);
                idx=i;
                cout<<count<<"\n";
            }
           }
           maxCount=max(maxCount,count);
        }
        if(count==n) return n-1;
        return maxCount;
    }
};