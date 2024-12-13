class Solution {
public:
    long long findScore(vector<int>& nums) {
        
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
        }
        long long ans=0;
        while(!pq.empty())
        {
              auto it=pq.top();
              pq.pop();
              int curr=it.first;
              int idx=it.second;
              if(nums[idx]!=-1)
              {
                ans+=curr;
                nums[idx]=-1;
              
              if(idx>0 && nums[idx-1]!=-1)
              {
                //    ans+=nums[idx-1];
                   nums[idx-1]=-1;
              }
              if(idx<n-1 && nums[idx+1]!=-1)
              {
                // ans+=nums[idx+1];
                nums[idx+1]=-1;
              }
              }
        }
        return ans;
    }
};