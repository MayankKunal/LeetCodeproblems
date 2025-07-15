class Solution {
public:
    bool isValid(string word) {
        
        int n=word.size();
int vowel=0,consonant=0;
        if(n<3) return false;
          
          for(int i=0;i<n;i++)
          {
            if((word[i]>='0' && word[i]<='9') || (word[i]>='a' && word[i]<='z') || (word[i]>='A' && word[i]<='Z')) 
            {
                if((word[i]>='a' && word[i]<='z') || (word[i]>='A' && word[i]<='Z'))
                {
                if(word[i]=='A' || word[i]=='E' || word[i]=='I' || word[i]=='O' || word[i]=='U' || word[i]=='a' || word[i]=='e' || word[i]=='i'||word[i]=='o'||word[i]=='u'){ vowel++;}

                else consonant++;
            }

            }
                 else 
            return false;
          }
               if(vowel && consonant) return true;
return false;

    }
};