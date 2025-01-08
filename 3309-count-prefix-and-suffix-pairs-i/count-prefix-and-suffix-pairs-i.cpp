class Solution {
    bool isPrefixAndSuffix(string &s1,string &s2)
    {
        if(s1.size()>s2.size())
        {
            return false;
        }
        int n=s1.size();
        int m=s2.size();
        cout<<s2.substr(m-n)<<" "<<s2.substr(0,n)<<endl;
        if(s1==s2.substr(0,n) && s1==s2.substr(m-n)) return true;
        return false;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        
        int n=words.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isPrefixAndSuffix(words[i],words[j]))
                count++;
            }
        }
        return count;
    }
};