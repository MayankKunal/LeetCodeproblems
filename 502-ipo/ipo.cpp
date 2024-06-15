class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        
        vector<pair<int,int>>projects;
        int n=profits.size();
        for(int i=0;i<n;i++)
        {
            projects.push_back({capital[i],profits[i]});
        }
        sort(projects.begin(),projects.end());
        priority_queue<int>profit;
        int j=0;
        for(int i=0;i<k;i++)
        {
           while(j<n && projects[j].first<=w)
           {
            profit.push(projects[j].second);
            j++;
           }   
           if(profit.empty()) break;
          else{
            int maxProfit=profit.top();
            profit.pop();
            w+=maxProfit;
          }
        }

        return w;
    }
};