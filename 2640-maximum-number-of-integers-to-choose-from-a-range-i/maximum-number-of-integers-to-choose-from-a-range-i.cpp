class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<long long >st;
        for(auto x:banned)
        {
            if(x<=n)
            st.insert(x);
        }
        long long sum=0;
        int count=0;
        for(int i=1;i<=n;i++)
        {
            if(st.find(i)==st.end())
            {
                if((sum+i)<=maxSum)
                {
                    sum+=i;
                    count++;
                }
                else
                 break;
            }
        }
        return count;
    }
};