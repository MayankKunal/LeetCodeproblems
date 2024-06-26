class Solution {
    void help(int i,int n,vector<int>&candidates,int target,vector<int>temp,vector<vector<int>>&ans)
    {
        if(i==n)
        {
            if(target==0)
            {
                ans.push_back(temp);
            }
            return;
        }
        
        help(i+1,n,candidates,target,temp,ans);
        if(target>=candidates[i])
        {
        temp.push_back(candidates[i]);
        help(i,n,candidates,target-candidates[i],temp,ans);
        temp.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>temp;
        vector<vector<int>>ans;
        int n=candidates.size();
        help(0,n,candidates,target,temp,ans);
        return ans;
    }
};