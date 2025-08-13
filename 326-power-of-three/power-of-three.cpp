class Solution {
public:
    bool isPowerOfThree(int n) {
        
        double m= (double)n;
        while(m>1)
        {
            m/=3;
        }
        if(m==1) return true;
        return false;
    }
};