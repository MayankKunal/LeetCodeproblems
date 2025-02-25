class Solution {
     const int MOD = 1e9 + 7;
public:
    int numOfSubarrays(vector<int>& arr) {
        
        int n=arr.size();
        unordered_map<int,int>mp;
        int sum=0;
        int ans=0;
        mp[sum]++;
        for(int i=0;i<n;i++)
        {
           sum+=arr[i];
           if(sum%2==0)
           {
            ans=(ans+mp[1]);
           }
           else if(sum%2==1)
           {
            ans=(ans+mp[0]);
           }
           ans%=MOD;
           mp[sum%2]++;
        }
        return ans;
    }
};