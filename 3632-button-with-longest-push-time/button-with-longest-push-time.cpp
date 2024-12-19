class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int n=events.size();
        vector<pair<int,int>>v;
        v.push_back({events[0][1],events[0][0]});
        for(int i=1;i<n;i++)
        {
            v.push_back({events[i][1]-events[i-1][1],events[i][0]});
        }

        sort(v.rbegin(),v.rend());
        int time=0;
        int idx=INT_MAX;
        // for(int i=0;i<n;i++)
        // {
        //     cout<<v[i].first<<" "<<v[i].second;
        // }
         for(int i=0;i<n;i++)
         {
            if(v[i].first>=time && idx>v[i].second)
            {
                idx=v[i].second;
                time=v[i].first;
            }
         }
         return idx;


    }
};