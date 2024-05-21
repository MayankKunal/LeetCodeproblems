class Solution {
    void help(int idx,int n,vector<int>&nums,vector<int>temp,vector<vector<int>>&ans)
    {
        if(idx==n)
        {
            ans.push_back(temp);
            return;
        }
        help(idx+1,n,nums,temp,ans);
        temp.push_back(nums[idx]);
        help(idx+1,n,nums,temp,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        int n=nums.size();
        vector<vector<int>>ans;
        help(0,n,nums,temp,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};