class Solution {
public:
    string reverseParentheses(string s) {
        
        int n=s.size();
        stack<int>st;
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') st.push(i);
            else if(s[i]==')')
            {
                int indx=st.top();
                st.pop();
                reverse(s.begin()+indx+1,s.begin()+i);
            }
        }
        for(char x:s)
        {
            if(x!='(' && x!=')') ans+=x;
        }
        return ans;
    }
};