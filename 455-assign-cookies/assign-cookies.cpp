class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        sort(g.begin(),g.end());
        reverse(g.begin(),g.end());
        sort(s.begin(),s.end());
        reverse(s.begin(),s.end());
        int count=0;
        int i=0,j=0;
        while(i<n && j<m)
        {
            if(s[j]>=g[i])
            {
                j++;
                i++;
                count++;
            }
            else if(s[j]<g[i])
            {
                i++;
            }
        }

        return count;
    }
};