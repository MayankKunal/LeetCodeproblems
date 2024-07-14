class Solution {
public:
    bool checkValidString(string s) {
        
        stack<char>bracket;
        stack<char>star;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(') bracket.push(i);
            else if(s[i]==')')
            {
                if(!bracket.empty()) bracket.pop();
                else 
                {
                    if(!star.empty()) star.pop();
                    else return false;
                }
            } 
            else
            {
              star.push(i);
            }
        }

        while(!bracket.empty() && !star.empty())
        {
            if(bracket.top()>star.top()) return false;
            bracket.pop();
            star.pop();
        }
        if(bracket.size()>0) return false;
        return true;
    }
};