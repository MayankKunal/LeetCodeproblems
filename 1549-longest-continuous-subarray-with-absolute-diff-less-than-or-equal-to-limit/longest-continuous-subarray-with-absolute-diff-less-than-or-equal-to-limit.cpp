class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        
        multiset<int>st;
        int left=0,right=0;
        int n=nums.size();
        int ans=0;
        while(right<n)
        {
            st.insert(nums[right]);
            while(!st.empty() && (*st.rbegin()-*st.begin())>limit)
            {
                   st.erase(st.find(nums[left]));
                   left++;
            }
             ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};