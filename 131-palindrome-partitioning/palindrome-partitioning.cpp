class Solution {
    bool isPalindrome(string s,int l,int r)
    {
        while(l<r)
        {
            if(s[l++]!=s[r--]) return false;
        }
        return true;
    }
    void help(int i,int n,string s,string str,vector<string> temp,vector<vector<string>>&ans)
    {
        if(i==n)
        {
           
            ans.push_back(temp);
        }
        // if(str!="" && isPalindrome(str)) temp.push_back(str);
        for(int idx=i;idx<n;idx++)
        {
              if(isPalindrome(s,i,idx))
              {
                temp.push_back(s.substr(i,idx-i+1));
                help(idx+1,n,s,str,temp,ans);
                temp.pop_back();
              }
            
        }
    }
public:
    vector<vector<string>> partition(string s) {
        
        vector<string>temp;
        vector<vector<string>>ans;
        help(0,s.size(),s,"",temp,ans);
            return ans;
    }
};