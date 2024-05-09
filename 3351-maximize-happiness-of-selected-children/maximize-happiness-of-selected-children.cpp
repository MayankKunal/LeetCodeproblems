class Solution {
bool static  compare(int a,int b)
    {
        return a>b;
    }
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        
        long long ans=0;

        sort(happiness.rbegin(),happiness.rend());
        // cout<<happiness[0];
      int i=0;
          while(k>0)
          {
            int temp=happiness[i]-i;
            
            if(temp>0) ans+=temp;
            else break;
            i++;
            k--;
          }
       return ans;
    }
};