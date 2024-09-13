class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>ans;
        for(auto query:queries)
        {
            int l=max(0,query[0]);
            int r=min(n,query[1]);
            int temp=0;
            for(int i=l;i<=r;i++)
            {
                temp^=arr[i];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};