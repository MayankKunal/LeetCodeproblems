class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
     int res=0;
        for(int x:nums)
        {
            res^=x;
        }
        // vector<int>ans;
        int i=0;
        while((res&1)!=1)
        {
            i++;
            res=res>>1;
        }
        int A=0;
        int B=0;
        for(int x:nums)
        {
            if(((x>>i)&1)==1)
            {
                A^=x;
            }
            else
            {
                B^=x;
            }
        }
        return {A,B};
    }
};