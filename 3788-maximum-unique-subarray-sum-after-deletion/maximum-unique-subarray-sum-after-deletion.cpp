class Solution {
public:
    int maxSum(vector<int>& nums) {
        
        unordered_set<int>st;
           int sum=0,maxSum=INT_MIN;
        for(int x:nums)
        {
            if(st.find(x)==st.end())
            {
                if(sum>0 && x<0)
                {
                    continue;
                } 
              sum+=x;
              
              st.insert(x);
            }
            maxSum=max(maxSum,sum);
            if(sum<0)
            {
                st.clear();
                 sum=0;
            }
            

        }
        return maxSum;
    }
};