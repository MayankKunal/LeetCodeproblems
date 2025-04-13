class Solution {
    int mod=1000000007;
    long long findPow(int x,long long n)
    {
        long long ans=1,mul=x;
        while(n>0)
        {
            if(n%2==1)
            {
                ans=( ans*mul )% mod;
                n--;
            }
            else
            {
                mul=(mul*mul) % mod;
                n/=2;
            }
        }
        return ans;
    }
public:
    int countGoodNumbers(long long n) {
        
        return (findPow(5,(n+1)/2)*findPow(4,n/2))%mod;
    }
};