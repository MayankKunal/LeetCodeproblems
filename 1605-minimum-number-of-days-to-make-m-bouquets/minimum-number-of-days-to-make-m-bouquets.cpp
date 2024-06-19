class Solution {
int help(vector<int>&bloomDay,int k,int mid)
{
     int count=0;
     int days=0;
     for(int x:bloomDay)
     {
       if(x<=mid)
       {
        count++;
       }  
       else
       {
        days+=count/k;
        count=0;
       }
     }
     days+=count/k;
     return days;
     
}
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int l=INT_MAX;
        int r=INT_MIN;
        for(int x:bloomDay)
        {
           l=min(l,x);
           r=max(r,x);
        }
        cout<<l<<" "<<r;
        int n=bloomDay.size();
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            int Bouquets=help(bloomDay,k,mid);
            if(Bouquets<m)
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