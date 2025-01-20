class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {

        int n=mat.size();
        int m=mat[0].size();
  unordered_map<int,pair<int,int>>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
              mp[mat[i][j]]={i,j};
            }
        }
       unordered_map<int,int>row;
       unordered_map<int,int>col;
       for(int i=0;i<arr.size();i++)
       {
           auto it=mp[arr[i]];
           int r=it.first;
           int c=it.second;
           row[r]++;
           col[c]++;
           if(row[r]==m || col[c]==n) return i;
       }
       return -1;

    }
};