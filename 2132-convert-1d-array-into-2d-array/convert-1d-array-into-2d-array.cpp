class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        
        vector<vector<int>>arr;
        int len=original.size();
        if(len!=(n*m)) return arr;
int k=0;
        for(int i=0;i<m;i++)
        {
            vector<int>temp;
            for(int j=0;j<n;j++)
            {
                 temp.push_back(original[k++]);
            }
            arr.push_back(temp);
        }
        return arr;
    }
};