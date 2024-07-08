class Solution {
public:
    int pivotInteger(int n) {
        vector<int>arr(n,0);
        for(int i=0;i<n;i++)
        {
            if(i==0) arr[i]=i+1;
            else arr[i]=arr[i-1]+i+1;
        }
 if(n==1) return 1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]==arr[n-1]-arr[i-1]) return i+1;
        }
        return -1;
    }
};