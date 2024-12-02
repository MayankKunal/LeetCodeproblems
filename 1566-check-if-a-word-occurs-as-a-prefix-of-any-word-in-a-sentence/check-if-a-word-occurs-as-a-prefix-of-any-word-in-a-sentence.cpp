class Solution {
    bool match(string &s1,string &s2)
    {
        int n=s1.size();
        // cout<<s1.substr(0,n);
        return s1==s2.substr(0,n);
    }
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int count=1;
        int n=sentence.size();
        string temp="";
        for(int i=0;i<n;i++)
        {
            if(sentence[i]==' ')
            {
                // cout<<temp;
                if(match(searchWord,temp)) return count;
                count++;
                temp="";
            }
            else
            temp+=sentence[i];
        }
  cout<<temp;
        // count++;
        if(match(searchWord,temp)) return count;
        return -1;
        
    }
};