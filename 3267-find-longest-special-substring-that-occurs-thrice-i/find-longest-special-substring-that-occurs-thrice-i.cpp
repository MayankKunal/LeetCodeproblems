class Solution {
    
    bool isSpecial(string s)
    {
        int n=s.size();
        char c=s[0];
        for(int i=0;i<n;i++)
        {
           if(s[i]!=c) return false;
        }
        return true;
    }
public:
    int maximumLength(string s) {
        int n=s.size();
        int res=-1;
        unordered_map<string, int> freq;
        for (int i = 0; i < n; ++i) {
            string temp = "";
            for (int j = i; j < n; ++j) {
                temp += s[j];
                if (isSpecial(temp)) {  // Only count special substrings
                    freq[temp]++;
                    if (freq[temp] >= 3) {
                        res = max(res, (int)temp.size());
                    }
                } else {
                    break;  // No need to continue for non-special substrings
                }
            }
        }
        return res;
    }
};