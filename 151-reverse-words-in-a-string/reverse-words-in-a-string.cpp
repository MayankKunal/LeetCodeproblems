class Solution {
public:
    string reverseWords(string s) {

       int n=s.size();
       string temp="";
       string ans="";
       for(int i=n-1;i>=0;i--)
       {
            if(s[i]==' ' && temp.size())
            {
                
                reverse(temp.begin(),temp.end());
                ans+=temp+" ";
                temp="";
            }
            else if(s[i]!=' ')
            {
                temp+=s[i];
            }
       }
       if(temp.size())
       {
         reverse(temp.begin(),temp.end());
                ans+=temp;
       }
       if(ans[ans.size()-1]==' ') ans.pop_back();
return ans;
    }
};