class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        set<int>prevBitAnd;
        int ans=INT_MAX;
        for(int x:nums)
        {
            set<int>newBitAnd;
            for(auto it:prevBitAnd)
            {
                newBitAnd.insert(it&x);
            }
            newBitAnd.insert(x);
            for(auto bit:newBitAnd)
            {
                ans=min(ans,abs(bit-k));
            }
            prevBitAnd=newBitAnd;
        }
        return ans;
    }
};