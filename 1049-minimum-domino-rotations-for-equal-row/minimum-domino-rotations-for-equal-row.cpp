class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
         
         vector<int>numCount(7,0);
         for(int i=0;i<n;i++)
         {
            numCount[tops[i]]++;
            numCount[bottoms[i]]++;
         }

         int maxEle=0;
         int maxCount=0;

         for(int i=1;i<=6;i++)
         {
            if(numCount[i]>maxCount)
            {
                maxCount=numCount[i];
                maxEle=i;
            }
         }
          int swaps1=0,swaps2=0;
         if(maxCount<n) return -1;
         for(int i=0;i<n;i++)
         {
           
            if(tops[i]!=maxEle && bottoms[i]!=maxEle)
            {
               return -1;
            }
             else if(tops[i]!=maxEle) swaps1++;
             else if(bottoms[i]!=maxEle) swaps2++;
         }
         
         return min(swaps1,swaps2);
    }
};