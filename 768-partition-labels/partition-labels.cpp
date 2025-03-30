class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n=s.size();
        unordered_map<char,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]=i;
        }
        int st=0,end=0;
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            end=max(end,mp[s[i]]);
            if(i==end)
            {
                ans.push_back(end-st+1);
                st=i+1;
            }
        }
        return ans;
    }
};