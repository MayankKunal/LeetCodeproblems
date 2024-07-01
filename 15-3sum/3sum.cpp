class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>ans;
        int n=nums.size();
        int l=0,r=n-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            l=i+1,r=n-1;
            while(l<r)
            {
                 if(nums[l]+nums[i]+nums[r]<0) l++;
                else if(nums[l]+nums[i]+nums[r]>0)
                {
                   r--;
                }
                else 
                {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1])l++;
                while(l<r && nums[r]==nums[r+1]) r--;
                }
                
            }
        }
       
        return ans;
    }
};