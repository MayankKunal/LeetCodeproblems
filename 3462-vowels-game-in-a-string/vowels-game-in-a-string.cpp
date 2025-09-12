class Solution {
public:
    bool doesAliceWin(string s) {
        
        unordered_map<char,int>vowels;
        vowels['a']++;
        vowels['e']++;
        vowels['i']++;
        vowels['o']++;
        vowels['u']++;
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(vowels.find(s[i])!=vowels.end())
            {
                count++;
            }
        }

        return count>=1;
    }
};