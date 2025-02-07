class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        
        // unordered_map<int,int>color;
        unordered_map<int,int>ball;
        unordered_map<int,int>color;
        vector<int>ans;
        for(auto query:queries)
        {
            int idx=query[0];
            int col=query[1];
            
            if(ball.find(idx)!=ball.end())
            {
                  color[ball[idx]]--;
                  if(color[ball[idx]]==0) color.erase(ball[idx]);
            }
            ball[idx]=col;
            color[ball[idx]]++;
            ans.push_back(color.size());
        }
        return ans;
    }
};