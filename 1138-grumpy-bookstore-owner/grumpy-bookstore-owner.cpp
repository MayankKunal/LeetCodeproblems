class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        
        int ans=0;
        int n=grumpy.size();
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==0)
            {
                ans+=customers[i];
            }
        }
        for(int i=0;i<minutes;i++)
        {
            if(grumpy[i]==1) ans+=customers[i];
        }
        int res=ans;
        int left=0,right=minutes;
        while(right<n)
        {
            if(grumpy[right]==1) res+=customers[right];
            if(grumpy[left]==1) res-=customers[left];
           
            left++;
            right++;
             ans=max(res,ans);
        }
        return ans;
    }
};