class Solution {
public:
    int findMaxK(vector<int>& nums) {
        
        unordered_set<int>st;
         int ans=-1;
        for(int x:nums)
        {
             
            if(st.find(-x)!=st.end())
            {
                ans=max(ans,abs(x));
            }
           st.insert(x);
        }
        return ans;
       
        // for(int x:nums)
        // {
        //     if(st.find(-x)!=st.end())
        //     {
        //         ans=max(ans,x);
        //     }
        // }
        // return ans;
    }
};