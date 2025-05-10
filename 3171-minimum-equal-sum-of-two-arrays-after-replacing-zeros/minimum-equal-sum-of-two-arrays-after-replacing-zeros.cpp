class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        
        int n=nums1.size();
        int m=nums2.size();
        long long sum1=0,sum2=0;
        long long countZero1=0,countZero2=0;

        for(int x:nums1)
        {
            if(x==0)
            countZero1++;
             sum1+=x;
        }

        for(int x:nums2)
        {
            if(x==0)
            countZero2++;
             sum2+=x;
        }
        cout<<sum1<<" "<<sum2;
        long long sumDiff=abs(sum1-sum2);
        if(sum1>sum2)
        {
            if(countZero1 && countZero2)
            {
                if(sumDiff>=(countZero2-countZero1))
                return sum1+countZero1;
                else return  sum1+(countZero2-countZero1);
            }
            else if(countZero2)
            {
                 if(sumDiff<countZero2) return -1;
                 return sum1;
            }
            else return -1;
        }

        else if(sum2>sum1)
        {
            if(countZero1 && countZero2)
            {cout<<"Print";
                if(sumDiff>=(countZero1-countZero2))
                return sum2+countZero2;

                else 
                cout<<"Print2";
                return  sum2+(countZero1-countZero2);
            }
            else if(countZero1)
            {
                 if(sumDiff<countZero1) return -1;
               
                 return sum2;
            }
            else return -1;
        }

        else
        {
             if(countZero1 && countZero2)
            {
                return sum2+max(countZero1,countZero2);
            }
            else if(countZero1 || countZero2) return -1;
            return sum1;
           
        }

        return -1;
    }
};