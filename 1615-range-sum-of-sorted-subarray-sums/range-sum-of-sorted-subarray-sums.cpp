class Solution {
long long mod=1000000007;
    
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long>arr;
for(int i=0;i<n;i++)
{
    long long sum=0;
    for(int j=i;j<n;j++)
    {
        sum=(sum+nums[j])%mod;
        arr.push_back(sum);
    }
    
}


       
        sort(arr.begin(),arr.end());
        int m=arr.size();
     left=left-1;
     right=min(m-1,right-1);
     long long ans=0;
     for(int i=left;i<=right;i++)
     {
        ans=(ans+arr[i])%mod;
     }
     return ans;
    }
};