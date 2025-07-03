class Solution {
    string genNext(string &s)
    {
        string ans="";
        int n=s.size();
        int i=0;
        for(int i=0;i<n;i++)
        {
            ans+=((s[i]-'a')+1)%26+'a';
        }
        ans=s+ans;
        return ans;
    }
public:
    char kthCharacter(int k) {
        
        string s="a";
        while(s.size()<k)
        {
            s=genNext(s);
        }

        return s[k-1];
        
    }
};