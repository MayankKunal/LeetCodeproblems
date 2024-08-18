class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        
        if(k==1) return nums;
        int n=nums.size();
        vector<int>arr(n,0);
        for(int i=1;i<n;i++)
        {
             if(nums[i]!=nums[i-1]+1)
             {
                arr[i]=1;
             }
        }
int c=0;
vector<int>ans;
        for(int i=0;i<k;i++)
        {
            if(arr[i]==1)c++;
        }
        if(c==0) ans.push_back(nums[k-1]);
        else ans.push_back(-1);
        for(int i=k;i<n;i++)
        {
            if(arr[i]==1)c++;
            if(arr[i-k+1]==1) c--;
            if(c==0) ans.push_back(nums[i]);
            else ans.push_back(-1);
        } 
        return ans;
    }
};