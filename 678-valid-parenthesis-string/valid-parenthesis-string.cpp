class Solution {
public:
    bool checkValidString(string s) {
        
        stack<int>st,st2;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') st.push(i);
            else if(s[i]==')')
            {
                if(!st.empty())
                st.pop();
                else if(!st2.empty())
                {
                    st2.pop();
                }
                else
                 return false;
            }
            else 
            {
                st2.push(i);
            }
        }
        while(!st.empty() && !st2.empty())
        {
            if(st.top()<st2.top())
            {
                st.pop();
                st2.pop();
            }
            else
            return false;
        }
        if(!st.empty()) return false;
        return true;
    }
};