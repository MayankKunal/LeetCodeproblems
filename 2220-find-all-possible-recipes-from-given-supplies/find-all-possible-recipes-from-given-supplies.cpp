class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        int n=recipes.size();
        unordered_set<string>st;
        for(auto supply:supplies)
        {
            st.insert(supply);
        }
unordered_map<string,vector<int>>adj;
vector<int>inDegree(n,0);
        for(int i=0;i<n;i++)
        {
            for(auto ing:ingredients[i])
            {
                if(!st.count(ing))
                {
                    adj[ing].push_back(i);
                    inDegree[i]++;
                }
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }
      vector<string>ans;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();

            ans.push_back(recipes[it]);
            for(auto idx:adj[recipes[it]])
            {
                inDegree[idx]--;
                if(inDegree[idx]==0)
                {
                    q.push(idx);
                }
        
            }
        }
        return ans;





    }
};