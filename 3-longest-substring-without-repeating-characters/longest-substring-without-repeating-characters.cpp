class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        int l=0,r=0;
        int ans=0;
        while(r<n)
        {
            mp[s[r]]++;
            while(mp[s[r]]>1)
            {
                mp[s[l]]--;
                if(mp[s[l]]==0) mp.erase(s[l]);
                l++;
            }
            ans=max(ans,r+1-l);
            r++;
        }
        return ans;
    }
};