class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<int>firstOccurance(26,-1);
        vector<int>lastOccurance(26,-1);
        for(int i=0;i<n;i++)
        {
            int curr=s[i]-'a';
            if(firstOccurance[curr]==-1)
            {
                firstOccurance[curr]=i;
            }
            lastOccurance[curr]=i;
        }
           int ans=0;
        for(int i=0;i<26;i++)
        {
            if(firstOccurance[i]==-1) continue;

            unordered_set<int>count;
            for(int idx=firstOccurance[i]+1;idx<lastOccurance[i];idx++)
            {
                    count.insert(s[idx]);
            }
            ans+=count.size();
        }
        return ans;
    }
};