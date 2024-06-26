class Solution {
    void help(int i,int n,vector<int>&nums,vector<int>temp,vector<vector<int>>&ans)
    {
        
            
            ans.push_back(temp);
        
        for(int idx=i;idx<n;idx++)
        {
            if(idx>i && nums[idx]==nums[idx-1]) continue;
            temp.push_back(nums[idx]);
            help(idx+1,n,nums,temp,ans);
            temp.pop_back();
        }
      
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<vector<int>>ans;
        help(0,n,nums,temp,ans);
        
        return ans;
    }
};