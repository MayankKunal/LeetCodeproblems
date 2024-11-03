class Solution {
public:
    bool rotateString(string s, string goal) {
        
        int n=s.size();
        int m=goal.size();
        if(n!=m) return false;
        
        while(m>0)
        {
            char lastBit=s[n-1];
            for(int i=n-1;i>0;i--)
            {
                   s[i]=s[i-1];
            }
            s[0]=lastBit;
            if(s==goal) return true;
            m--;
        }

        return false;
    }
};