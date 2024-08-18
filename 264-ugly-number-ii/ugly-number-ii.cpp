class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>t(n+1,0);
         t[1]=1;
         int i2;
         int i3;
         int i5;
         i2=i3=i5=1;
         for(int i=2;i<=n;i++)
         {
            int uglyNo2=t[i2]*2;
            int uglyNo3=t[i3]*3;
            int uglyNo5=t[i5]*5;

            t[i]=min(uglyNo2,min(uglyNo3,uglyNo5));
            if(t[i]==uglyNo2)
            {
                i2++;
            }
            if(t[i]==uglyNo3) i3++;
            if(t[i]==uglyNo5) i5++;
         }
         return t[n];
    }
};