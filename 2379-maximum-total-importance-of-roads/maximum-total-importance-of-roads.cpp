class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        
        vector<long long>inDegree(n,0);
        for(auto road:roads)
        {
            inDegree[road[0]]++;
            inDegree[road[1]]++;
        }
       long long ans=0;
        sort(inDegree.begin(),inDegree.end());
         for(int i=0;i<n;i++)
         {
            ans+=(long long)(i+1)*inDegree[i];
         }
         return ans;
    }
};