class Solution {
    bool isPrime(int n)
    {
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0) return false;
        }
        return true;
    }
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int>ans;
        if(left==1) left++;
        for(int i=left;i<=right;i++)
        {
            if(isPrime(i))
            {
                ans.push_back(i);
            }
        }
        int a=-1,b=-1;
        int minDiff=INT_MAX;
        int n=ans.size();
        for(int i=0;i<n-1;i++)
        {
            if((ans[i+1]-ans[i])<minDiff)
            {
                minDiff=ans[i+1]-ans[i];
                a=ans[i];
                b=ans[i+1];
            }
        }
        
        return {a,b};
    }
};