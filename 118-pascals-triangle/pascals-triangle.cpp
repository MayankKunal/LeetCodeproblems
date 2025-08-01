class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>>ans;
        vector<int>temp;
        temp.push_back(1);
        ans.push_back(temp);
        for(int i=1;i<numRows;i++)
        {
            temp.resize(i+1);
            temp[0]=1;
            temp[i]=1;
            for(int j=1;j<i;j++)
            {
                temp[j]=ans[i-1][j-1]+ans[i-1][j];
            }
            ans.push_back(temp);
        } 

        return ans;
    }
};