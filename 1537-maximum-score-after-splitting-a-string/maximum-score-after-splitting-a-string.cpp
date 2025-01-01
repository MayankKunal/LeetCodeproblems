class Solution {
    int count1(string s)
    {
        int count=0;
        for(char &c:s)
        {
        if(c=='1') count++;
        }
        return count;
    }
    int count0(string s)
    {
        int count=0;
        for(char &c:s)
        {
        if(c=='0') count++;
        }
        return count;
    }
public:
    int maxScore(string s) {
        int n=s.size();
        int ans=0,maxCount=0;
        for(int len=1;len<=n-1;len++)
        {
          ans=count0(s.substr(0,len));
          ans+=count1(s.substr(len));
          maxCount=max(maxCount,ans);
        }
        return maxCount;
    }
};