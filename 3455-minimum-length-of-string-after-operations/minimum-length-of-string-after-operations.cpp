class Solution {
public:
    int minimumLength(string s) {
        
        unordered_map<int,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
        int ans=0;
        for(auto x:mp)
        {
            
                ans+=(x.second%2==0)?2:1;
             
        }
        return ans;
    }
};