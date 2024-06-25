class Solution {
    double help(double x,int n)
    {
            if(n==0) return 1;
               
              if(n%2==0)
              {
                return help(x*x,n/2);
              }
              else
             return x*help(x,n-1);
    }
public:
    double myPow(double x, int n) {
        
       if(n==0) return 1;
        if(n<0) {
            n = abs(n);
            x = 1/x;
        }
        if(n%2==0){
            return myPow(x*x, n/2);
        }
        else{
            return x*myPow(x, n-1);
        }
    }
};