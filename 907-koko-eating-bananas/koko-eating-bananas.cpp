class Solution {
    int help(vector<int>&piles,long long mid)
    {
         int time=0;
         for(int x:piles)
         {
            time+=(x/mid);
            if(x%mid)
            {
                time+=1;
            }
         }
         return time;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n=piles.size();

        long long l=1,r=0;
        for(int x:piles)
        {
            r+=x;
        }
       int ans=-1;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            
            int time=help(piles,mid);
             if(time<=h)
             {
               ans=mid;
               r=mid-1;
             }
             else
             {
                l=mid+1;
             }
        }
        return ans;
    }
};