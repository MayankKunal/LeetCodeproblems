class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        unordered_set<string>st;
          vector<string>ans;
        for(string supply: supplies)
        {
            st.insert(supply);
        }
       int m=recipes.size();
        int n=ingredients.size();
        for(int k=0;k<m;k++)
        {
           
        for(int i=0;i<n;i++)
        {
             if(st.find(recipes[i])!=st.end()) continue;
            bool flag=true;
            for(int j=0;j<ingredients[i].size();j++)
            {
                 if(st.find(ingredients[i][j])==st.end())
                 {
                       flag=false;
                       break;
                 }
            }
            if(flag)
            {
               
                 st.insert(recipes[i]);
            }
        }
        }

         for(int i=0;i<n;i++)
        {
            bool flag=true;
            for(int j=0;j<ingredients[i].size();j++)
            {
                 if(st.find(ingredients[i][j])==st.end())
                 {
                       flag=false;
                       break;
                 }
            }
            if(flag)
            {
               
                 ans.push_back(recipes[i]);
            }
        }

        return ans;

    }
};