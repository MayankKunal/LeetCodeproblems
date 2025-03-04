class Solution {
public:
    bool checkPowersOfThree(int n) {
          
          string ternary="";
          while(n>0)
          {
             int rem=n%3;
             n=n/3;
             ternary+=rem+'0';
          }
          int m=ternary.size();
          for(int i=0;i<m;i++)
          {
            if(ternary[i]=='2') return false;
          }
          return true;
    }
};