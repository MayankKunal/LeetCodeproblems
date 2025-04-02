class Solution {
    bool isPalindrome(string s)
    {
        int n=s.size();
        int l=0,r=n-1;
        while(l<r)
        {
            if(s[l]!=s[r])
              return false;
              l++;
              r--;
        }
        return true;
        
    }

    void help(string s,vector<string>&word)
    {
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                word.push_back(s.substr(i,j-i+1));
            }
        }
    }
    
public:
    int longestPalindrome(string s, string t) {

     vector<string>ans1;
     vector<string>ans2;
     ans1.push_back("");
     ans2.push_back("");
     help(s,ans1);
     help(t,ans2);
    int ans=0;
    for(int i=0;i<ans1.size();i++)
    {
    for(int j=0;j<ans2.size();j++)
    {
            string word=ans1[i]+ans2[j];
            int m=word.size();
            if(isPalindrome(word))
            {
                ans=max(ans,m);
            }
    }
    }
    return ans;
    }
};