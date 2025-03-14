class Solution {
    long long help(vector<int>&candies,int candi)
    {
        long long ans=0;
        int n=candies.size();
     if(candi==0) return 0;
        for(int i=0;i<n;i++)
        {
              ans+=(candies[i]/candi);
        }
        return ans;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        
        int n=candies.size();
        long long l=1,r=0;
        for(int i=0;i<n;i++)
        {
            r=max(r,(long long)candies[i]);
        }
        if(n==1)
        {
            return candies[0]/k;
        }
         int ans=0;
         while(l<=r)
         {
            long long mid=(l+r)/2;
            long long noOfChildren=help(candies,mid);
            {
                if(noOfChildren>=k)
                {
                    ans=mid;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }
         }

         return ans;

    }
};