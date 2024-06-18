class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        
        int n=difficulty.size();
        vector<pair<int,int>>v;
        // int n=profit.size();
        for(int i=0;i<n;i++)
        {
            v.push_back({difficulty[i],profit[i]});
        }
        sort(v.begin(),v.end());
        int j=0;
        int ans=0;
        priority_queue<int>pq;
        while(j<worker.size())
        {
            int capacity=worker[j];
            int maxres=0;
            for(int i=0;i<v.size();i++)
            {
                if(capacity>=v[i].first)
                {
                    maxres=max(maxres,v[i].second);
                }
                else break;
            }
            ans+=maxres;
            j++;
            
        }
        
        return ans;
    }
};