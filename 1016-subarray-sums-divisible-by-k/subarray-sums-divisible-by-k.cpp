class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0]=1;
        int count=0;
        int sum=0;
        for(int x:nums)
        {
            sum+=x;
            int remainder=sum%k;
            if(remainder<0) remainder=remainder+k;
            if(mp.find(remainder)!=mp.end())
            {
                count+=mp[remainder];
            }
            mp[remainder]++;
        }
        return count;
    }
};