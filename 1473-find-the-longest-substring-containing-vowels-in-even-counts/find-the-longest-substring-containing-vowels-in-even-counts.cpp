class Solution {
public:
    int findTheLongestSubstring(string s) {
        
        string key="00000";
        unordered_map<string,int>mp;
        mp[key]=-1;
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            {
                 if(s[i]=='a') 
                 {
                    if(key[0]=='0') key[0]='1';
                    else key[0]='0';
                 }
                 
                 if(s[i]=='e') 
                 {
                    if(key[1]=='0') key[1]='1';
                    else key[1]='0';
                 }
                 if(s[i]=='i') 
                 {
                    if(key[2]=='0') key[2]='1';
                    else key[2]='0';
                 }
                 if(s[i]=='o') 
                 {
                    if(key[3]=='0') key[3]='1';
                    else key[3]='0';
                 }
                 else
                 {
                    if(key[4]=='0') key[4]='1';
                    else key[4]='0';
                 }
            }

            if(mp.find(key)!=mp.end())
            {
                ans=max(ans,i-mp[key]);
            }
            else
            {
                mp[key]=i;
            }
        }

        return ans;
    }
};