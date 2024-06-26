class Solution {
   void help(int i,int n,int arr[],int k,int sum,vector<int>temp,vector<vector<int>>&ans)
    {
        if(i==n)
        {
            if(sum==0 && temp.size()==k)
             {
                ans.push_back(temp);
             }
             return;
        }
        if(sum<0) return;
        help(i+1,n,arr,k,sum,temp,ans);
        if(arr[i]<=sum)
        {
        temp.push_back(arr[i]);
        help(i+1,n,arr,k,sum-arr[i],temp,ans);
        temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        int arr[9]={1,2,3,4,5,6,7,8,9};
        vector<int>temp;
        vector<vector<int>>ans;
        help(0,9,arr,k,n,temp,ans);
        return ans;
    }
};