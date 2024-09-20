class Solution {
    vector<int>solve(string exp)
    {
        vector<int>res;
        for(int i=0;i<exp.size();i++)
        {
            if(exp[i]=='+'||exp[i]=='-'||exp[i]=='*')
            {
            vector<int>leftRes=solve(exp.substr(0,i));
            vector<int>rightRes=solve(exp.substr(i+1));
            for(auto &x:leftRes)
            {
                for(auto &y:rightRes)
                {
                  if(exp[i]=='+')
                  res.push_back(x+y);
                  else if(exp[i]=='-')
                  res.push_back(x-y);
                  else res.push_back(x*y);   
                }
            }
            }
        }
        if(res.size()==0)
        res.push_back(stoi(exp));
        return res;
    }
public:
    vector<int> diffWaysToCompute(string expression) {
        
        return solve(expression);
    }
};