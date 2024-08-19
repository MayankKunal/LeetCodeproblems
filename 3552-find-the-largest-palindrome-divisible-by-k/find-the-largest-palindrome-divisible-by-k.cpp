class Solution {
     
int isdivisible7(string num)
{
    int n = num.length(), gSum=0;
    if (n == 0)
        return 1;
 
    // Append required 0s at the beginning.
    if (n % 3 == 1) {
        num="00" + num;
        n += 2;
    }
    else if (n % 3 == 2) {
        num= "0" + num;
        n++;
    }
 
    // add digits in group of three in gSum
    int i, GSum = 0, p = 1;
    for (i = n - 1; i >= 0; i--) {
 
        // group saves 3-digit group
        int group = 0;
        group += num[i--] - '0';
        group += (num[i--] - '0') * 10;
        group += (num[i] - '0') * 100;
 
        gSum = gSum + group * p;
 
        // generate alternate series of plus
        // and minus
        p *= (-1);
    }
 
    return (gSum % 7 == 0);
}
public:
    string largestPalindrome(int n, int k) {
        
        string ans="";
        if(n==1)
        {
            if(k==1) return "9";
            else if(k==2) return "8";
            else if(k==3) return "9";
            else if(k==4) return "8";
            else if(k==5) return "5";
            else if(k==6) return "6";
            else if(k==7) return "7";
            else if(k==8) return "8";
            else return "9";
        }
        else if(n==2)
        {
            if(k==1)      return "99";
            else if(k==2) return "88";
            else if(k==3) return "99";
            else if(k==4) return "88";
            else if(k==5) return "55";
            else if(k==6) return "66";
            else if(k==7) return "77";
            else if(k==8) return "88";
            else return "99";
        }
        else if(n==3)
        {
            if(k==1) return "999";
            else if(k==2) return "898";
            else if(k==3) return "999";
            else if(k==4) return "888";
            else if(k==5) return "595";
            else if(k==6) return "888";
            else if(k==7) return "959";
            else if(k==8) return "888";
            else return "999";
        }
        else
        {
             for(int i=1;i<=n;i++)
             {
                ans+='9';
             }
             if(k==1 || k==3 || k==9) return ans;
             else if(k==2) 
             {
                ans[0]='8';
                ans[n-1]='8';
                return ans;
             }
             else if(k==4)
             {
                    ans[0]='8';
                    ans[1]='8';
                    ans[n-1]='8';
                    ans[n-2]='8';
                    return ans;
             }
             else if(k==5) 
             {
                ans[0]='5';
                ans[n-1]='5';
                return ans;
             }
             else if(k==6)
             {
                   ans[0]='8';
                   ans[n-1]='8';
                   if(n%2==1)
                   {
                    ans[n/2]='8';
                   }
                   else 
                   {
                    ans[(n/2)]='7';
                    ans[(n/2)-1]='7';
                   }
                   return ans;
             }
             else if(k==7)
             {
                      for(char ch='9';ch>='1';ch--)
                      {
                           if(n%2==1)
                           {
                            ans[n/2]=ch;
                           }
                           else 
                           {
                            ans[n/2]=ch;
                            ans[n/2-1]=ch;
                           }
                           if(isdivisible7(ans)) return ans;
                      }
             }
             else if(k==8)
             {
           ans[0]='8';
           ans[1]='8';
           ans[2]='8';
           ans[n-1]='8';
           ans[n-2]='8';
           ans[n-3]='8';
           return ans;
             }
        }
        return "ans";
        // return ans;
    }
    
};