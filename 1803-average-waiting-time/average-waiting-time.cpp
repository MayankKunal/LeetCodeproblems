class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        double currentTime=0;
    double waitingTime=0;
    double n=customers.size();
    for(auto x:customers)
    {
        if(currentTime<x[0])
        {
            currentTime=x[0];
        }
        currentTime+=x[1];
        waitingTime+=currentTime-x[0];
    }
      return double(waitingTime/n);
    }
};