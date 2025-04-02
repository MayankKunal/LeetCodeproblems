class Solution {
public:
    vector<int> minCosts(vector<int>& cost) {
        
        int n=cost.size();
        int currCost=cost[0];
        vector<int>ans;
        ans.push_back(currCost);
        for(int i=1;i<n;i++)
        {
               if(cost[i]>currCost)
               {
                ans.push_back(currCost);
               }
               else
               {
                currCost=cost[i];
                ans.push_back(currCost);
               }
        }
        return ans;
    }
};