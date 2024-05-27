class Solution {
    int help(vector<int>&arr,int mid)
    {
        int count=0;
        for(int num:arr)
        {
            if(num>=mid) count++;
        }
        return count;
    }
public:
    int specialArray(vector<int>& nums) {

       int l=0,r=nums.size();
       sort(nums.begin(),nums.end());
       while(l<=r)
       {
        int mid=(l+r)/2;
          
          int x=help(nums,mid);
          if(x==mid) return mid;
          else if(x<mid)
          {
                  r=mid-1;
          }
          else
          {
               l=mid+1;
          }
       }    

       return -1;
    }

};