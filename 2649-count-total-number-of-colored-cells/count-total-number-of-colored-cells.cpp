class Solution {
public:
    long long coloredCells(int n) {
        long long ans=1;
        long long append=4;
        n=n-1;
        while(n--)
        {
          ans+=append;
          append+=4;
        }
        return ans;
    }
};