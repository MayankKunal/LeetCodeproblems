class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        for(int i=0;i<k-1;i++)
        {
            colors.push_back(colors[i]);
        }
    int ans=0;
        int left=0,right=1;
        n=colors.size();
        while(right<n)
        {
            if(colors[right]==colors[right-1])
            {
                left=right;
                right++;
                continue;
            }
       right++;
            if(right-left<k)
            {
                continue;
            }
            left++;
            ans++;
        
        }
        return ans;
    }
};