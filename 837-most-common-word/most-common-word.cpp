class Solution {
    class myComparator {
    public:
        bool operator()(const pair<int,string>& a, const pair<int,string>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        }
    };

public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        unordered_map<string,int> mp;
        string temp="";
        int n = paragraph.size();

        for(int i=0;i<n;i++)
        {
            if((paragraph[i]>='a' && paragraph[i]<='z') || (paragraph[i]>='A' && paragraph[i]<='Z'))
            {
                if(paragraph[i]>='A' && paragraph[i]<='Z')
                    paragraph[i]+=32;

                temp += paragraph[i];
            }
            else
            {
                if(temp.size()!=0)
                {
                    mp[temp]++;
                    temp="";
                }
            }
        }

        if(temp.size()!=0) mp[temp]++; // 🔥 fix

        vector<pair<int,string>> ans;
        for(auto x:mp)
        {
            ans.push_back({x.second,x.first});
        }

        sort(ans.begin(), ans.end(), myComparator());

        unordered_set<string> st(banned.begin(), banned.end());

        for(int i=0;i<ans.size();i++) // 🔥 fix
        {
            if(st.find(ans[i].second)==st.end()) 
                return ans[i].second;
        }

        return "";
    }
};