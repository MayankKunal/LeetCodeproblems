class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int n=nums.size();
        vector<int>flip(n,0);
        int flipCount=0;
        int totalFlip=0;
        for(int i=0;i<n;i++)
        {
            if((i-k)>=0 && flip[i-k]==1)
            {
                flipCount--;;
            }
            
            if((nums[i]+flipCount)%2==0)
            {
                if((k+i)>n) return -1;
                  flipCount++;
                  totalFlip++;
                  flip[i]=1;
            }
        }

        return totalFlip;
    }
};