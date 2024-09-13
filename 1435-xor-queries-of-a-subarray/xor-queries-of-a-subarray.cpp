class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
       vector<int>xorPrefix(n);
     
       int ans=0;
       
       for(int i=0;i<n;i++)
       {
          ans^=arr[i];
          xorPrefix[i]=ans;
          
       }
       vector<int>res;
       for(auto query:queries)
       {
         int l=max(0,query[0]);
         int r=min(n,query[1]);
            if(l==0) res.push_back(xorPrefix[r]);
           else 
           res.push_back(xorPrefix[r]^xorPrefix[l-1]);  
       }
       return res;
    }
};