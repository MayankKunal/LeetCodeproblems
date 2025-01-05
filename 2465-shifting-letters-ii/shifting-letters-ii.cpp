class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        int n=s.size();
        int m=shifts.size();
        vector<int>shift(n+1,0);
        for(int i=0;i<m;i++)
        {
             int start=shifts[i][0];
             int end=shifts[i][1];
             int dir=shifts[i][2];
            
              if(dir==0)
              {
                shift[start]-=1;
                shift[end+1]+=1;
              }
              else
              {
                       shift[start]+=1;
                shift[end+1]-=1;
              }
        }
     int newShift=0;
        for(int i=0;i<n;i++)
        {
            newShift+=shift[i];
            int currLetter=s[i]-'a';
            int newLetter=currLetter+newShift;
            newLetter=(newLetter)%26;
            if(newLetter<0) newLetter+=26;
            s[i]='a'+newLetter;
        }
        return s;
    }
};