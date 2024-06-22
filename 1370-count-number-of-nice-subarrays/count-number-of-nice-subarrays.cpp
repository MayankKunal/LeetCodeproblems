class Solution {
public:
int help(vector<int>&arr,int k)
{
    int n=arr.size();
    int left=0,right=0,total=0,res=0;
    while(right<n)
    {
        if(arr[right]%2)
        {
            total++;
        }
        while(total>k)
        {
            if(arr[left]%2)
            {
                total--;
            }
            left++;
        }
        res+=right-left+1;
           right++;
    }
    return res;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
      return help(nums,k)-help(nums,k-1);      
    }
};