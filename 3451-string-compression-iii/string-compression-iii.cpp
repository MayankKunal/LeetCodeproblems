class Solution {
public:
    string compressedString(string word) {

       string ans="";
       int count=1;
       char curr=word[0];
       int n=word.size();
       for(int i=1;i<n;i++)
       {
          if(word[i]==curr)
          {
            count++;
            if(count==10)
            {
                ans+=to_string(count-1);
            ans+=curr;
            count=1;
            curr=word[i];
            }
          }
          else
          {
            ans+=to_string(count);
            ans+=curr;
            count=1;
            curr=word[i];
          }
       } 
       if(count)
       {
        ans+=to_string(count);
            ans+=curr;
            count=1;
       }
       return ans;
    }
};