class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        
        int n=blocks.size();
        int black=0,white=0;
        int ans=INT_MAX;
        for(int i=0;i<k;i++)
        {
           if(blocks[i]=='B') black++;
           else  white++;
        }

        ans=min(ans,white);
        for(int i=k;i<n;i++)
        {
            if(blocks[i]=='W') white++;
            if(blocks[i-k]=='W') white--;
            ans=min(ans,white);
        }
        return ans;
    }
};