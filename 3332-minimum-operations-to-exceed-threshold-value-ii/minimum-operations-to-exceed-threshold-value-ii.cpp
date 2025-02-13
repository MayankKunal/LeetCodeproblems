class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        priority_queue<long long,vector<long long>,greater<long long>>pq;
        for(int x:nums)
        {
            pq.push(x);
        }
  int count=0;
        while(pq.top()<k)
        {
            long long first=pq.top();
            pq.pop();
            long long second=pq.top();
            pq.pop();
            long long newVal=min(first,second)*2+max(first,second);
            pq.push(newVal);
            count++;
        }
        return count;
    }
};