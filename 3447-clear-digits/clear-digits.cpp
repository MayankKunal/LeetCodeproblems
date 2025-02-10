class Solution {
public:
    string clearDigits(string s) {
     int n=s.size();
     string ans="";
     for(int i=0;i<n;i++)
     {
        if(s[i]>='0' && s[i]<='9')
        {
            if(ans.size()==0) continue;
            else ans.pop_back();
        }
        else
        {
            ans+=s[i];
        }
     }   

     return ans;
    }
};