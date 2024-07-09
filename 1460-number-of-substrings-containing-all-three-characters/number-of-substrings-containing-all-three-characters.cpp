class Solution {
    int help(string &s,int k)
    {
        int n=s.size();
        int l=0,r=0;
        unordered_map<char,int>mp;
        int ans=0;
        while(r<n)
        {
              mp[s[r]]++;
              while(mp.size()>k)
              {
                  mp[s[l]]--;
                  if(mp[s[l]]==0) mp.erase(s[l]);
                  l++;
              }
              ans+=r-l+1;
              r++;
        }
        return ans;
    }
public:
    int numberOfSubstrings(string s) {
        
        return help(s,3)-help(s,2);
    }
};