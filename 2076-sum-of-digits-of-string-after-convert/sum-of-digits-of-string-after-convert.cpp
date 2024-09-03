class Solution {
public:
    int getLucky(string s, int k) {
        
        int n=s.size();
        string word="";
        for(int i=0;i<n;i++)
        {
            word+=to_string(s[i]-'a'+1);
        }
        int sum=0;
        while(k--)
        {
            int n=word.size();
        
            for(int i=0;i<word.size();i++)
            {
                 sum+=word[i]-'0';
            }
            word=to_string(sum);
            if(k!=0) sum=0;
        }
        return sum;
    }
};