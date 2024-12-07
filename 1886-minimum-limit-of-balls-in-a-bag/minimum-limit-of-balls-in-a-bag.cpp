class Solution {
    int help(vector<int>&nums,int cap)
    {
             int op=0;
             for(int x:nums)
             {

               if(x%cap==0)
               {
                op+=(x/cap)-1;
               }  
               else
               {
                op+=x/cap;
               }
                 
             }
             cout<<op<<endl;
             return op;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int l=1,r=0;
        for(int x:nums)
        {
            r=max(r,x);
        }
        int ans=0;
        while(l<=r)
        {
            int mid=(l+r)/2;
            cout<<mid<<" ";
            int op=help(nums,mid);
            if(op>maxOperations)
            {
                l=mid+1;
            }
            else
            {
                ans=mid;
                r=mid-1;
            }

        }
        return ans;
    }
};