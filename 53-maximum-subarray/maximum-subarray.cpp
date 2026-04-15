class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n=nums.size();
        int ans=0,temp=0;
        int mini=INT_MIN;
        bool flag=false;
        for(int x:nums)
        {
            if(x>0) flag=true; 
            temp+=x;
            mini=max(mini,x);
            if(temp<0) temp=0;
            ans=max(ans,temp);
        }
        if(flag)
        return ans;
        else
        return mini;
    }
};