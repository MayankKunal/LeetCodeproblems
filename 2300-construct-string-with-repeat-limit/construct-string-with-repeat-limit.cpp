class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        
       map<char,int>mp;
       for(char x:s)
       {
        mp[x]++;
       }
       string ans="";
        while(mp.size()>0)
        {
             
                  auto it=mp.rbegin();
                char c=it->first;
                int total=it->second;
            if(total<=repeatLimit)
            {
                mp.erase(c);
                   while(total--)
                   {
                    ans+=c;
                   }
            }
            else
            {
                mp.erase(c);
                int i=1;
                while(i<=repeatLimit)
                {
                    ans+=c;
                    i++;
                }
                total-=repeatLimit;
                if(mp.size())
                {
                   auto itt=mp.rbegin();
                   char cc=it->first;
                   int count=it->second;
                   ans+=cc;
                   count--;
                   if(count==0) mp.erase(cc);
                   else mp[cc]=count;
                mp[c]=total;
                }
                else break;
            }
        }
        return ans;
    }
};