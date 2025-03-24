class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        
        sort(meetings.begin(),meetings.end());
        
        int start=meetings[0][0];
        int end=meetings[0][1];
        int daysMeetingOrganised=0;
        for(int i=1;i<meetings.size();i++)
        {
            if(meetings[i][0]<=end)
            {
                start=min(start,meetings[i][0]);
                end=max(end,meetings[i][1]);
            }
            else
            {
                daysMeetingOrganised+=end-start+1;
                start=meetings[i][0];
                end=meetings[i][1];
            }
        }
         daysMeetingOrganised+=end-start+1;
      return days-daysMeetingOrganised;
                 
        
        
        
    }
};