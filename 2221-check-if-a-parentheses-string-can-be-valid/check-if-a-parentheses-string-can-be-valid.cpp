class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int>st;
        stack<int>st2;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' && locked[i]=='1')
             st.push(i);
             else if(s[i]==')' && locked[i]=='1')
             {
                if(!st.empty() || !st2.empty())
                {
                    if(!st.empty()) st.pop();
                    else st2.pop();
                }
                else return false;
             }
             else
             {
                st2.push(i);
             }
        }
          
          while(!st.empty()&& !st2.empty())
          {
            if(st.top()>st2.top()) return false;
            else
            {
                st.pop();
                st2.pop();
            }
          }
           if(st.empty()&& st2.size()%2==0) return true;
           return false;
    }
};