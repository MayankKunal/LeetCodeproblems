class Solution {
public:
    int maxScore(string s) {
        
        int n=s.size();
        int onesCount=0;
        for(char c:s)
        {
            if(c=='1') onesCount++;
        }

        // if(s[0]=='1') onesCount-=1;
        // cout<<onesCount;
        int maxCount=0,zeroCount=0;;
        for(int i=0;i<n-1;i++)
        {
             if(s[i]=='0') zeroCount++;
             else if(s[i]=='1') onesCount--;
             maxCount=max(maxCount,(zeroCount+onesCount));
        }
        return maxCount;

    }
};