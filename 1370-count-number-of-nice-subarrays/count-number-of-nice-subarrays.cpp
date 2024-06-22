class Solution {
public:
int help(vector<int>&arr,int k)
{
    int n=arr.size();
int l=0,r=0,count=0,total=0;
while(r<n)
{
    if(arr[r]%2==1) total++;
    while(total>k)
    {
        if(arr[l]%2==1) total--;
        l++;
    }
       count+=r-l+1;
          r++;
}
return count;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return help(nums,k)-help(nums,k-1);
    }
};