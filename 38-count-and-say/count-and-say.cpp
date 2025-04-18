class Solution {
    string describe(string s)
    {
        int n=s.size();
        int count=1;
        string ans="";
        for(int i=1;i<n;i++)
        {
            if(s[i]==s[i-1])
            {
                count++;
            }
            else
            {
                ans+=to_string(count)+s[i-1];
                count=1;
            }
        }
        ans+=to_string(count)+s.back();
        return ans;
    }
public:
    string countAndSay(int n) {
        string ans="1";
        for(int i=1;i<n;i++)
        {
           ans=describe(ans);
        }
        return ans;
    }
};