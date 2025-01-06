class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        int n=boxes.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++)
        {
            if(boxes[i]=='1') st.insert(i);
        }
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
             for(auto x:st)
             {
                ans[i]+=abs(x-i);
             }
        }
        return ans;
    }
};