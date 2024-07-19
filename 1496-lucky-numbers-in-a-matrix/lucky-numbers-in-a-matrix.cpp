class Solution {
     vector<int> minimum(vector<vector<int>>&matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int ele=INT_MAX;
            for(int j=0;j<m;j++)
            {
                ele=min(ele,matrix[i][j]);
            }
            ans.push_back(ele);
        }
        return ans;
    }
    vector<int> maximum(vector<vector<int>>&matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>ans;
        for(int i=0;i<m;i++)
        {
            int ele=INT_MIN;
            for(int j=0;j<n;j++)
            {
                ele=max(ele,matrix[j][i]);
            }
            ans.push_back(ele);
        }
        return ans;
    }
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
          vector<int>mini=minimum(matrix);
          vector<int>maxi=maximum(matrix);
  unordered_map<int,int>mp;
  for(int x:maxi) 
  {
    cout<<x<<" ";
    mp[x]++;
    }
vector<int>ans;
  for(int x:mini){
    if(mp.find(x)!=mp.end()) ans.push_back(x);
  }
  return ans;

 

    }
};