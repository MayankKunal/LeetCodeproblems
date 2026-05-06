class Solution {
    double distance(double x,double y)
    {
        return sqrt(pow(x,2)+pow(y,2));
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
         priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>,greater<pair<double,pair<int,int>>>>pq;
         for(auto point:points)
         {
            double x=(double)point[0];
            double y=(double)point[1];
            pq.push({distance(x,y),{(int)x,(int)y}});
         }
         vector<vector<int>>ans;
         while(k-- && !pq.empty())
         {
            auto it=pq.top();
            pq.pop();
            ans.push_back({it.second.first,it.second.second});
         }
         return ans;
    }
};