class Solution {
public:
    int minLength(string s) {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<s.size();j++)
            {
                if(s[j]=='A' && s[j+1]=='B' || s[j]=='C' && s[j+1]=='D')
                {
                   string leftHalf=s.substr(0,j);
                   string rightHalf=s.substr(j+2,s.size()-j+2);
                   s=leftHalf+rightHalf;
                   cout<<s<<" ";
                }
            }
        }

        return s.size();
    }
};