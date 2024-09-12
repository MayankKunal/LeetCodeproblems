class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        unordered_map<char,int>mp;
        for(auto x:allowed)
        {
            mp[x]++;
        }
        int count=0;
        for(auto x:words)
        {
            bool flag=true;
            for(int i=0;i<x.size();i++)
            {
                if(mp.find(x[i])==mp.end())
                {
                 flag=false;
                 break;
                }
            }
            if(flag) count++;
        }
        return count;
    }
};