class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int mod=1e9+7;
        priority_queue<int,vector<int>,greater<int>>q;
        for(int x:nums)
        {
            q.push(x);
        }
        while(k--)
        {
            int ele=q.top();
               q.pop();
               ele+=1;
               q.push(ele);
        }
        long long ans=1;
        while(!q.empty())
        {
            ans=(ans*q.top())%mod;
            q.pop();
        }
        return ans;
    }
};