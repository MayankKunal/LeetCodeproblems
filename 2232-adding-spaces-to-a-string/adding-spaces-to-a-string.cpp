class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {

     string ans="";
     int n=spaces.size();
     int sIdx=0;
     for(int i=0;i<n;i++)
     {
        ans+=s.substr(sIdx,spaces[i]-sIdx);
        ans+=" ";
        sIdx=spaces[i];
     }   

     ans+=s.substr(sIdx);
     return ans;
    }
};