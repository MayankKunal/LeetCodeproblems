class Solution {
    static bool compare(pair<int,pair<int,int>>&a,pair<int,pair<int,int>>&b)
    {
        if(a.first<b.first) return true;
        if(a.first==b.first && a.second.second<b.second.second) return true;
        return false;
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        unordered_map<char,char>mp;
        for(int i=0;i<=9;i++)
        {
            char indx=i+'0';
            char value=mapping[i]+'0';
            mp[indx]=value;
        }
        vector<pair<int,pair<int,int>>>arr;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            string s=to_string(num);
            string value="";
            for(int i=0;i<s.size();i++)
            {
                value+=mp[s[i]];
            }
            int val=stoi(value);
            arr.push_back({val,{nums[i],i}});
        }
        sort(arr.begin(),arr.end(),compare);
        vector<int>ans;
        for(auto x:arr)
        {
            cout<<x.first<<" ";
            ans.push_back(x.second.first);
        }
        return ans;
    }
};