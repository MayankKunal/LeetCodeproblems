class Solution {
public:
    string makeFancyString(string s) {
        
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(i>=2 && s[i]==s[i-1] && s[i]==s[i-2])
            {
                  continue;
            }
            else
            {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};