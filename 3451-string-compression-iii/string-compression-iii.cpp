class Solution {
public:
    string compressedString(string word) {
        string comp="";
        
        int n=word.size();
        int count=1;
        char c=word[0];
        for(int i=1;i<n;i++)
        {
            if(c==word[i] && count<9)
            {
                count++;
            }
            else
            {
                comp+=to_string(count);
                comp+=c;
                count=1;
                c=word[i];
            }
        }
        comp+=to_string(count);
                comp+=c;
        return comp;
    }
};