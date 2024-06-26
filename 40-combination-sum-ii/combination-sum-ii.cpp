class Solution {
    void help(int i,int n,vector<int>&arr,int target,vector<int>temp,vector<vector<int>>&ans)
    {
        
            if(target==0)
            {
            ans.push_back(temp);
             return;
            }
           
        
        if(target<0) return;
        for(int idx=i;idx<n;idx++)
        {
            if(idx>i && arr[idx]==arr[idx-1]) continue;
            if(arr[idx]>target) break;
            temp.push_back(arr[idx]);
            help(idx+1,n,arr,target-arr[idx],temp,ans);
            temp.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int>temp;
        vector<vector<int>>ans;
        sort(candidates.begin(),candidates.end());
        help(0,n,candidates,target,temp,ans);
        return ans;
    }
};