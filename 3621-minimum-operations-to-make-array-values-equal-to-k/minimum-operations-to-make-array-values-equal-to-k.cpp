class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int n=nums.size();
        int minEle=INT_MAX;
        unordered_set<int>st;
        for(int x:nums)
        {
            minEle=min(minEle,x);
            st.insert(x);
        }
        if(minEle<k) return -1;
        if(minEle==k)
        return st.size()-1;
        return st.size();

    }
};