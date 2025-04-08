class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        
        int n=nums.size();
        unordered_map<int,int>mp;
        unordered_map<int,int>secondLastOccurance;
        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                secondLastOccurance[nums[i]]=mp[nums[i]];
                mp[nums[i]]=i;
            }
            else
            {
                mp[nums[i]]=i;
            }
        }

        // if(secondLastOccurance.size()==0) return 0;

        int maxPos=-1;
        for(auto x:secondLastOccurance)
        {
            maxPos=max(maxPos,x.second);
        }
        if(maxPos==-1) return 0;
        maxPos+=1;
        cout<<maxPos;
         if(maxPos%3==0) return maxPos/3;
         return (maxPos/3)+1;
    }
};