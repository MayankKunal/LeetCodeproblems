class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
       
       priority_queue<pair<double,pair<int,int>>>pq;
        
        for(auto cla:classes)
        {
            double currRatio=(double)cla[0]/(double)cla[1];
            double newRatio=(double)(cla[0]+1)/(double)(cla[1]+1);
            pq.push({(newRatio-currRatio),{cla[0],cla[1]}});
        }
        for(int i=0;i<extraStudents;i++)
        {
            auto it=pq.top();
            pq.pop();
            cout<<it.first;
            int passStudents=it.second.first+1;
            int totalStudents=it.second.second+1;
            double currRatio=(double)passStudents/(double)totalStudents;
            double newRatio=(double)(passStudents+1)/(double)(totalStudents+1);
            pq.push({newRatio-currRatio,{passStudents,totalStudents}});
        }
        // auto it=pq.top();
        //     pq.pop();
        //     cout<<it.first;
        //     int passStudents=it.second.first+extraStudents;
        //     int totalStudents=it.second.second+extraStudents;
        //     pq.push({(double)passStudents/(double)totalStudents,{passStudents,totalStudents}});
        double ans=0;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            ans+=double(it.second.first)/double(it.second.second);
        }
        return ans/classes.size();
    }
};