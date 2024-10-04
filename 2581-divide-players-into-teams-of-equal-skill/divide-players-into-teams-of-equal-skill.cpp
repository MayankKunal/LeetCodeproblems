class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        int n=skill.size();
        sort(skill.begin(),skill.end());
        int netSkill=skill[0]+skill[n-1];
        int l=0,r=n-1;
        long long ans=0;
        while(l<r)
        {
         if(skill[l]+skill[r]!=netSkill)
         {
             return -1;
         }
         else
         {
            ans+=skill[l]*skill[r];
         }
         l++;
         r--;
        }
        return ans;
    }
};