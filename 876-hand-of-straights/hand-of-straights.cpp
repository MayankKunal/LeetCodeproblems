class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n=hand.size();
        if(n%groupSize)
        {
            return false;
        }
        map<int,int>mp;
        for(int x:hand)
        {
            mp[x]++;
        }
        sort(hand.begin(),hand.end());
        for(int x:hand)
        {
            if(mp[x]==0)
            {
                continue;
            }
            for(int j=0;j<groupSize;j++)
            {
                int currCard=x+j;
                if(mp[currCard]==0)
                {
                    return false;
                }
                mp[currCard]--;
            }
        }
        return true;
    }
};