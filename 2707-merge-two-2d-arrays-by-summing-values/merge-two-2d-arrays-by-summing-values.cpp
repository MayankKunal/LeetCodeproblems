class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        unordered_map<int,int>mp1,mp2;
        for(auto num1:nums1)
        {
            mp1[num1[0]]=num1[1];
        }
            for(auto num2:nums2)
            {
                mp2[num2[0]]=(num2[1]);
            }
vector<vector<int>>ans;
        for(int i=1;i<=1000;i++)
        {       int val=0;
            if(mp1.find(i)!=mp1.end())
            {
                   val+=mp1[i];
            }
             if(mp2.find(i)!=mp2.end())
            {
                val+=mp2[i];
            }
            if(val!=0)
            {
                  ans.push_back({i,val});
            }
        }
        return ans;
    }
};