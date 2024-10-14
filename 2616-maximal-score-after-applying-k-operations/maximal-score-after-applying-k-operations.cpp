class Solution {
    int ceilVal(int x)
    {
        if(x%3==0) return x/3;
        return (x/3)+1;

    }
public:
    long long maxKelements(vector<int>& nums, int k) {
        
        priority_queue<int>pq;
        for(int x:nums)
        {
            pq.push(x);
        }
        long long sum=0;
        while(k--)
        {
            int x=pq.top();
            sum+=x;
            pq.pop();
           int val=ceilVal(x);
           cout<<val;
           pq.push(val);
        }
        return sum;
    }
};