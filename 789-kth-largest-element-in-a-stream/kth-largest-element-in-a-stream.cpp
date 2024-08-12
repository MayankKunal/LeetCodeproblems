class KthLargest {
public:
   priority_queue<int,vector<int>,greater<int>>pq;
   int m;
    KthLargest(int k, vector<int>& nums) {
        m=k;
       auto endPointer = nums.begin() + min(k, (int)nums.size());
        pq = priority_queue<int, vector<int>, greater<int>> (nums.begin(), endPointer);
        for (int i = k; i < nums.size(); ++i) {
            pq.push(nums[i]);
            pq.pop();
        }
    }
    
    
    int add(int val) {
     
     
     pq.push(val);
     if(pq.size()>m)
     {
            pq.pop();
     }
      return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */