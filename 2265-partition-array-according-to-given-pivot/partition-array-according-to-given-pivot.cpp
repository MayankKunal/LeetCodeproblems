class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
         
         vector<int>less,greater;
         int p=0;
         for(int i=0;i<n;i++)
         {
            if(nums[i]<pivot) less.push_back(nums[i]);
            else if(nums[i]>pivot) greater.push_back(nums[i]);
            else p++;
         }
         vector<int>ans;
         for(int i=0;i<less.size();i++)
         {
            ans.push_back(less[i]);
         }
         while(p--) ans.push_back(pivot);
        for(int i=0;i<greater.size();i++) ans.push_back(greater[i]);
        return ans;
    }
};