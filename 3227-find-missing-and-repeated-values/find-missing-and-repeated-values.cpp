class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
int a,b;
        unordered_set<int>st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(st.find(grid[i][j])!=st.end())
                a=grid[i][j];
                else
                st.insert(grid[i][j]);
            }
        }
        
        for(int i=1;i<=n*n;i++)
        {
            if(st.find(i)==st.end())
            {
                b=i;
                break;
            }
        }

     return {a,b};
    }
};