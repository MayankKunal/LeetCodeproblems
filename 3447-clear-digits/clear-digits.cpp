class Solution {
public:
    string clearDigits(string s) {
        
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                st.push(i);
            }
        }
       string ans="";
        while(!st.empty())
        {
            int idx=st.top();
            ans+=s[idx];
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};