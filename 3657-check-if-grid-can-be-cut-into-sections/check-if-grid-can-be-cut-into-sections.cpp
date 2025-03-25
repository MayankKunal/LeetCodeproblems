class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int,int>>v1;
vector<pair<int,int>>v2;
        for(auto x:rectangles)
            {
                v1.push_back({x[0],x[2]});
                v2.push_back({x[1],x[3]});
            }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
int count=0;
        int s=v1[0].first,e=v1[0].second;
        for(int i=1;i<v1.size();i++)
            {
                if(e<=v1[i].first)
                {
                    count++;
                    s=v1[i].first;
                    e=v1[i].second;
                }
                else
                {
                    s=max(s,v1[i].first);
                    e=max(e,v1[i].second);
                }
            }
        if(count>=2) return true;
count=0;
        s=v2[0].first,e=v2[0].second;
        for(int i=1;i<v2.size();i++)
            {
                if(e<=v2[i].first)
                {
                    count++;
                    s=v2[i].first;
                    e=v2[i].second;
                }
                else
                {
                    s=max(s,v2[i].first);
                    e=max(e,v2[i].second);
                }
            }
        if(count>=2) return true;
        return false;
    }
};