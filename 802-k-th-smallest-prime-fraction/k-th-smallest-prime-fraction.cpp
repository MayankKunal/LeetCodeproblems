class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        
        priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>>pq;
         int n=arr.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double temp = (double)arr[i] / arr[j];
                pq.push({temp,{arr[i],arr[j]}});
            }
        }
    
    while( !pq.empty() && k>1)
    {
     pq.pop();
    k--;
    }
    if(!pq.empty()) return {pq.top().second.first,pq.top().second.second};

    return {-1,-1};
    }

    
};