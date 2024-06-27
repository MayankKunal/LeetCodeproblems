class Solution {
    void help(int i,int n,string &digits,unordered_map<char,vector<char>>&mp,string temp,vector<string>&ans)
    {
        if(i==n)
        {
            ans.push_back(temp);
            return;
        }
       int m=mp[digits[i]].size();
       for(int idx=0;idx<m;idx++)
       {
            help(i+1,n,digits,mp,temp+mp[digits[i]][idx],ans);
       }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,vector<char>>mp{
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p','q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w','x', 'y', 'z'}}
        };
         int n=digits.size();
         
         string temp="";

         vector<string>ans;
         if(n==0)
         return ans;
        help(0,n,digits,mp,temp,ans);
        return ans;
    }
};