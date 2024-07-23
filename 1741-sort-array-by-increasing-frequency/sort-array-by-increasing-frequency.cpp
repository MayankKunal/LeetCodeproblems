class Solution {
   static bool customCompare(pair<int,int>&a,pair<int,int>&b)
    {
         if (a.first == b.first) 
            return a.second > b.second;
        return a.first < b.first;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int x:nums)
        {
            mp[x]++;
        }
vector<pair<int,int>>arr;
        for(auto x:mp)
        {
            arr.push_back({x.second,x.first});
        }
        sort(arr.begin(),arr.end(),customCompare);
        vector<int>ans;
        for(auto x:arr)
        {
            while(x.first--)
            ans.push_back(x.second);
        }
        return ans;
    }
};