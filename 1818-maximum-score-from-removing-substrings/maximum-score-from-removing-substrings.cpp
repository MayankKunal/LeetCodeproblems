class Solution {
    void reverse(stack<char>&st)
    {
        if(st.empty()) return;

        char ele=st.top();
        st.pop();
        reverse(st);
        st.push(ele);
    }
public:
    int maximumGain(string s, int x, int y) {
        
        string s1="",s2="";
        if(x>y)
        {
            s1="ab";
            s2="ba";
        }
        else
        {
            swap(x,y);
            s1="ba";
            s2="ab";
        }
        int n=s.size();
        int ans=0;
        string st="";
        for(int i=0;i<n;i++)
        {
          if(!st.empty() && st.back()==s1[0] && s[i]==s1[1])
          {
            st.pop_back();
            ans+=x;
          }
          else
          {
            st.push_back(s[i]);
          }
        }
  string st2="";
 
   int m=st.size();
       for(int i=0;i<m;i++)
       {
               if(!st2.empty() && st2.back()==s2[0] && st[i]==s2[1])
          {
            st2.pop_back();
            ans+=y;
          }
          else
          {
            st2.push_back(st[i]);
          }
       }
 cout<<"s "<<s<<"s1 "<<st<<"s2 "<<st2;
        return ans;
    }
};