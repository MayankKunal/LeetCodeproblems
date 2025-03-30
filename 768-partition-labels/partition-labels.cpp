class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        int n=s.size();
        unordered_map<char,int>last;
        unordered_map<char,int>start;
        
        for(int i=0;i<n;i++)
        {
            if(start.find(s[i])==start.end())
            {
                start[s[i]]=i;
            }
            last[s[i]]=i;
        }

       vector<pair<int,int>>arr;
        for(int i=0;i<n;i++)
        {
        
            arr.push_back({start[s[i]],last[s[i]]});
        }
        sort(arr.begin(),arr.end());

   int  st=arr[0].first;
   int e=arr[0].second;
     vector<int>ans;
        for(int i=1;i<arr.size();i++)
        {
           if(arr[i].first<e)
           {
            st=min(st,arr[i].first);
            e=max(e,arr[i].second);
           }
           else
           {
              ans.push_back(e-st+1);
              st=arr[i].first;
              e=arr[i].second;
           }
        }
        ans.push_back(e-st+1);
        return ans;
    }
};