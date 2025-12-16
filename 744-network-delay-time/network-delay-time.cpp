class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        unordered_map<int,vector<pair<int,int>>>graph;
        for(auto time:times)
        {
            int u=time[0];
            int v=time[1];
            int t=time[2];
            graph[u].push_back({v,t});
        }

        pq.push({0,k});
        vector<int>time(n+1,INT_MAX);
        time[k]=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int t=it.first;
            int node=it.second;
            for(auto adj:graph[node])
            {
                int tim=adj.second;
                int adjNode=adj.first;
                if((t+tim)<time[adjNode])
                {
                    time[adjNode]=(t+tim);
                    pq.push({time[adjNode],adjNode});
                }
            }
        }
        int ans=0;
        for(int i=1;i<time.size();i++)
        {
          ans=max(ans,time[i]);
        }
        if(ans==INT_MAX) return -1;
        return ans;
          
    }
};