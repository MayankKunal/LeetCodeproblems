class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n=arr.size();
        vector<int>temp=arr;
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mp;
        int k=1;
        for(int i=0;i<n;i++)
        {
            if(mp.find(temp[i])==mp.end())
            mp[temp[i]]=k++;
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(mp[arr[i]]);
        }
        return ans;
    }
};