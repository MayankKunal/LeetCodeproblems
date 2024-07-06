class Solution {
public:
    int passThePillow(int n, int time) {
        
        int dir=1;
        int step=1;
        for(int i=1;i<=time;i++)
        {
            if(step==n) dir=-1;
            if(step==1) dir=1;
          step+=dir;
        }
             return step;
    }
};