class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int>ans;
       map<int,int>mp;
        for(int x:arr1)
        {
            mp[x]++;
        }

        for(int x:arr2)
        {
            while(mp[x])
            {
                ans.push_back(x);
                mp[x]--;
            }
        }
        for(auto &it:mp)
        {
            while((it.second)--)
            ans.push_back(it.first);
        }

        return ans;
    }
};