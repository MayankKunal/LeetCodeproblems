class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        vector<int>prefix=arr;
        vector<int>suffix=arr;
        int n=arr.size();
        for(int i=1;i<n;i++)
        {
            prefix[i]=max(prefix[i-1],arr[i]);
        }
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=min(suffix[i+1],arr[i]);
        }
   int count=1;
        for(int i=1;i<n;i++)
        {
          if(prefix[i-1]<suffix[i]) count++;
        }
        return count;
    
    }
};