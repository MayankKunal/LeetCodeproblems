class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        
          int n=nums.size();
          priority_queue<pair<int,int>>pq;
          for(int i=0;i<n;i++)
          {
            pq.push({nums[i],i});
          }
     
          set<int>mp;
          while(k--)
          {
            mp.insert(pq.top().second);
            pq.pop();
          }
             vector<int>ans;
          for(auto x:mp)
          {
            ans.push_back(nums[x]);
          }
          return ans;

    }
};