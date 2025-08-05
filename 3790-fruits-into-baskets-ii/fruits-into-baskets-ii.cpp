class Solution {
    int help(vector<int>&fruits,vector<int>&baskets)
    {
        int n=fruits.size();
      int i=0,j=0,count=0;
       while(i<n && j<n)
       {
         if(fruits[i]<=baskets[j])
         {
            i++;
            j++;
            count++;
         }
         else 
         {
            j++;
         }
       }
       return n-count;
    }
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        
       int n=fruits.size();
       unordered_map<int,int>mp;
       int count=0;
       for(int i=0;i<n;i++)
       {
         int fruitCount=fruits[i];
         for(int j=0;j<n;j++)
         {
            if(baskets[j]>=fruits[i] && mp.find(j)==mp.end())
            {
                mp[j]++;
                count++;
                break;
            }
         }
       }
       return n-count;
    }
};