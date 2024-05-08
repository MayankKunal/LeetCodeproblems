class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        
        priority_queue<pair<int,int>>q;
        for(int i=0;i<score.size();i++)
        {
            q.push({score[i],i});
        }
       int n=score.size();
        vector<string>ans(n);
        int i=1;
        while(!q.empty())
        {
            auto it=q.top();
            q.pop();
            int idx=it.second;
            string temp;
            if(i==1) temp="Gold Medal";
            else if(i==2) temp="Silver Medal";
            else if(i==3) temp="Bronze Medal";
            else temp=to_string(i);
            ans[idx]=temp;
            i++;
        }

        return ans;
    }
};