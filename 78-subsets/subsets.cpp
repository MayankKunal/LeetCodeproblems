class Solution {
void help(int i,int n,vector<int>&nums,vector<int>temp,vector<vector<int>>&ans)
{
      ans.push_back(temp);
       
    for(int idx=i;idx<n;idx++)
    {
        temp.push_back(nums[idx]);
     help(idx+1,n,nums,temp,ans);
       temp.pop_back();
    }
    // help(i+1,n,nums,temp,ans);
    // temp.push_back(nums[i]);
    // help(i+1,n,nums,temp,ans);
    // temp.pop_back();
}

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int>temp;
        vector<vector<int>>ans;
        int n=nums.size();
        help(0,n,nums,temp,ans);
        return ans;
    }
};