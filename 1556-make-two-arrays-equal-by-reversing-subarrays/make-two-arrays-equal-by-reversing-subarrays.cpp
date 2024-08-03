class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        int n=target.size();
        int m=arr.size();
        unordered_map<int,int>mp;
        for(int x:arr)
          mp[x]++;
        for(int x:target)
        {
            if(mp.find(x)==mp.end()) return false;
            else 
            {
                mp[x]--;
                if(mp[x]==0) mp.erase(x);
            }
        }
        return true;
    }
};