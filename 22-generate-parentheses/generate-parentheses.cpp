class Solution {
    void help(int o,int c,int n,string temp,vector<string>&ans)
    {
        if(o==n && c==n)
        {
            ans.push_back(temp);
            return ;
        }
        if(o<n)
        {
              help(o+1,c,n,temp+'(',ans);
        }
        if(c<n && c<o)
        {
            help(o,c+1,n,temp+')',ans);
        }

    }
public:
    vector<string> generateParenthesis(int n) {
        
  vector<string>ans;

        help(0,0,n,"",ans);
        return ans;
    }
};