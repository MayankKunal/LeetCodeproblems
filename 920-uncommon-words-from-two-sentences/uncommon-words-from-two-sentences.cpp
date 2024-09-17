class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        unordered_map<string,int>mp;
        string temp="";
        for(auto x:s1)
        {
            if(x==' ') 
            {
                if(temp.size()) mp[temp]++;
                temp="";
            }
            else
            {
                temp+=x;
            }
        }
        if(temp.size()) mp[temp]++;
        temp="";
        for(auto x:s2)
        {
            if(x==' ') 
            {
                if(temp.size()) mp[temp]++;
                temp="";
            }
            else
            {
                temp+=x;
            }
        }
        if(temp.size()) mp[temp]++;
        vector<string>ans;
        for(auto &x:mp)
        {
            if(x.second==1) ans.push_back(x.first);
        }
        return ans;
    }
};