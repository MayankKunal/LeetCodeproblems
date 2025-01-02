class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        unordered_set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        int n=words.size();
       vector<int>ans(n,0);

        for(int i=0;i<n;i++)
        {
            int m=words[i].size();
            if(st.find(words[i][0])!=st.end() && st.find(words[i][m-1])!=st.end())
            {
                if(i==0) ans[i]=1;
                else ans[i]=ans[i-1]+1;
            }
            else
            if(i!=0)
             ans[i]=ans[i-1];
        }
        vector<int>res;
        for(int i=0;i<queries.size();i++)
        {
            int s=queries[i][0],e=queries[i][1];
            int count=0;
            if(s!=0)
             count=ans[e]-ans[s-1];
             else count=ans[e];
              res.push_back(count);
        }
        return res;
    }
};