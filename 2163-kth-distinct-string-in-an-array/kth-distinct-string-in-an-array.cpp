class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int>mp;
        for(string s:arr)
        {
            mp[s]++;
        }
        for(string x:arr)
        {
            if(mp[x]==1)
            {
                k--;
                if(k==0) return x;
            }
        }
        return "";
        
    }
};