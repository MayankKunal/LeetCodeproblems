class Solution {
    
      
public:
    string clearStars(string s) {
        int n=s.size();
        auto comp = [](const pair<char, int>& a, const pair<char, int>& b) {
            if (a.first == b.first) {
                return a.second < b.second; // larger index pehle ayega
            }
            return a.first > b.first; // smaller character pehle ayega
        };
        unordered_set<int>st;
       priority_queue<pair<char,int>,vector<pair<char,int>>,decltype(comp)>pq(comp);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='*')
            {
                st.insert(i);
                if(!pq.empty())
                {
                    st.insert(pq.top().second);
                    pq.pop();
                }
            }
            else
            {
               pq.push({s[i],i});
            }
        }
        string ans="";
        for(int i=0;i<n;i++)
        {
            if(st.find(i)==st.end()) ans+=s[i];
        }
        
        return ans;
    }
};