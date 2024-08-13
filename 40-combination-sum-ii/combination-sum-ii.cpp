class Solution {
    void help(int idx,int n,vector<int>&candidates,int target,vector<vector<int>>&ans,vector<int>temp)
    {
       
        if(target==0)
        { 
            ans.push_back(temp);
        return;
          }
          if(target<0) return;
       for(int i=idx;i<n;i++)
       {
         if(i>idx && candidates[i]==candidates[i-1]) continue;
         if(candidates[i]>target) break;
         temp.push_back(candidates[i]);
         help(i+1,n,candidates,target-candidates[i],ans,temp);
         temp.pop_back();
       }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
 sort(candidates.begin(),candidates.end());
  vector<int>temp;

  int n=candidates.size();
  vector<vector<int>>ans;
  help(0,n,candidates,target,ans,temp);

  
  return ans;
    }
};