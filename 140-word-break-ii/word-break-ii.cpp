class Solution {
     void help(int idx, int n, string s, unordered_set<string>& st, string temp, vector<string>& ans) {
        if (idx == n) {
            ans.push_back(temp);
            return;
        }
        for (int j = idx; j < n; j++) {
            string word = s.substr(idx, j - idx + 1); // extract substring from idx to j
            if (st.find(word) != st.end()) {
                string newTemp = temp.empty() ? word : temp + " " + word; // add space if temp is not empty
                help(j + 1, n, s, st, newTemp, ans); // recursively call for the next part
            }
        }
    }
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string>st;
          st.insert(wordDict.begin(),wordDict.end());
          int n=s.size();
          vector<string>ans;
          help(0,n,s,st,"",ans);
          return ans;
    }
};