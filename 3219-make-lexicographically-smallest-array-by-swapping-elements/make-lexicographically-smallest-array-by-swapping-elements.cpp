class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n=nums.size();
        vector<int>vec=nums;
        sort(vec.begin(),vec.end());
        int grpNum=0;
        unordered_map<int,int>numGrp;
        numGrp[vec[0]]=grpNum;
        unordered_map<int,list<int>>grpList;
        grpList[grpNum].push_back(vec[0]);
        for(int i=1;i<n;i++)
        {
            if(abs(vec[i]-vec[i-1])>limit)
            {
                grpNum++;
            }
            numGrp[vec[i]]=grpNum;
            grpList[grpNum].push_back(vec[i]);
        }
   vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int findGrp=numGrp[nums[i]];
            ans.push_back(grpList[findGrp].front());
            grpList[findGrp].pop_front();
        }
        return ans;
    
    }
};