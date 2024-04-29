class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int EleXor=start^goal;
       int count=0;
        while(EleXor)
        {
            if(EleXor&1) count++;

            EleXor=EleXor>>1;
        }
        return count;
    }
};