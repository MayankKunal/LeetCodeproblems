class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int n=arrays.size();
        int m=arrays[0].size();
        int maxi=arrays[0][m-1];
        int mini=arrays[0][0];
        int diff=INT_MIN;
        for(int i=1;i<n;i++)
        {
            int m=arrays[i].size();
            int currMin=arrays[i][0];
            int currMax=arrays[i][m-1];
            diff=max(diff,max(abs(currMin-maxi),abs(currMax-mini)));
            mini=min(currMin,mini);
            maxi=max(currMax,maxi);
        }
        return diff;
    }
};