class Solution {
    void help(int n,string tiles,string temp,unordered_set<string>&st,vector<int>&vis)
    {
        st.insert(temp);
       for(int idx=0;idx<n;idx++)
       {
        if(!vis[idx])
        {
            vis[idx]=1;
        help(n,tiles,temp+tiles[idx],st,vis);
        vis[idx]=0;
        }
       }

    }
public:
    int numTilePossibilities(string tiles) {
        
        int n=tiles.size();

        unordered_set<string>st;
        vector<int>vis(n,0);
        help(n,tiles,"",st,vis);
        return st.size()-1;;
    }
};