class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int>mp;
    for(auto c:t)
    {
        mp[c]++;
    }
    int count=mp.size();
    int l=0,r=0;
   int ans=INT_MAX;
    string res="";
    int n=s.size();
    int head=-1;
    while(r<n)
 {
       if(mp.find(s[r])!=mp.end())
       {
          mp[s[r]]--;
          if(mp[s[r]]==0) count--;
       }
       while(count==0)
    {
        if(ans>(r-l+1)) 
        {
            ans=(r-l+1);
            head=l;
        }
          if(mp.find(s[l])!=mp.end())
          {
             mp[s[l]]++;
             if(mp[s[l]]==1) count++;
          }
          l++;
    }
       
       r++;
    }
    if(head==-1) return "";
    else
     return s.substr(head,ans);
 }
};