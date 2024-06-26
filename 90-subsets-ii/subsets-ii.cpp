class Solution {
    void help(int i,int n,vector<int>&nums,vector<int>temp,set<vector<int>>&ans)
    {
        if(i==n)
        {
            sort(temp.begin(),temp.end());
            ans.insert(temp);
            return;
        }
       help(i+1,n,nums,temp,ans);
       temp.push_back(nums[i]);
       help(i+1,n,nums,temp,ans);
       temp.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp;
        set<vector<int>>st;
        vector<vector<int>>ans;
        help(0,n,nums,temp,st);
        for(auto x:st)
        {
            ans.push_back(x);
        }
        return ans;
    }
};