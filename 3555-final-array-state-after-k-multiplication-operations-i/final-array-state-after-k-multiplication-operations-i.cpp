class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
        }
    while(k--)
    {
        auto it=pq.top();
        pq.pop();
        int num=it.first;
        int idx=it.second;
        num*=multiplier;
        pq.push({num,idx});
    }
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int num=it.first;
            int idx=it.second;
            nums[idx]=num;
        }
        return nums;
    }
};