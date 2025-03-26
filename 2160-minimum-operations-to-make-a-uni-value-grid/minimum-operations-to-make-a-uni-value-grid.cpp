class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<int>arr;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
m=arr.size();
        int currRem=arr[0]%x;
        cout<<"Rem->"<<currRem;
        for(int i=0;i<m;i++)
        {
            int rem=arr[i]%x;
            if(rem!=currRem) return -1;
        }
        int ans=0;
        
        if(n%2==0)
        {
            int val=arr[(m/2)-1];
            cout<<"Val->"<<val;
            for(int i=0;i<m;i++)
            {
                ans+=(abs(val-arr[i])/x);
            }
        }
        else
        {
            int val=arr[m/2];
            for(int i=0;i<m;i++)
            {
                ans+=(abs(val-arr[i]))/x;
            }
        }
        return ans;

    }
};