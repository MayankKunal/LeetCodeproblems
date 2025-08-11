class Solution {
int mod=1e9+7;
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        
        vector<int>nums;
          while(n>0)
          {
            int d=1;
           while(d<n)
           {
               d*=2;
           }
           if(d==n)
           {
              nums.push_back(d);
              n-=d;
           }
           else
           {
            nums.push_back(d/2);
            n-=d/2;
           }

          }
          sort(nums.begin(),nums.end());
            vector<int>ans;
          for(auto query:queries)
          {
            int s=query[0];
            int e=query[1];
            long long temp=1;
           for(int i=s;i<=e;i++)
           {
            temp=(temp%mod*nums[i])%mod;
           }
           ans.push_back(temp);
          }
          return ans;
    }
};