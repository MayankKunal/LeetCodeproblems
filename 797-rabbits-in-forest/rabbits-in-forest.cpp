class Solution {
public:
    int numRabbits(vector<int>& answers) {
        
        unordered_map<int,int>st;
        int ans=0;
        for(auto x:answers)
        {
            if(st.find(x)==st.end())
            {
                ans+=x+1;
                st[x]++;
            }
            else 
            {
                if(st[x]==x+1)
                {
                    st[x]=1;
                    ans+=x+1;
                }
                else
                st[x]++;
            }
        }
        return ans;
    }
};