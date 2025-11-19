class Solution {
    int help(int n)
    {
        if(n==0 || n==1) return n;
        return help(n-1)+help(n-2);
    }
public:
    int fib(int n) {
        
        return help(n);
    }
};