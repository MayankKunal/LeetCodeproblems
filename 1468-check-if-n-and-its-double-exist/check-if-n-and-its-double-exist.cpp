class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
    unordered_set<int>st;
    for(auto x:arr)
    {
        if(st.find(2*x)!=st.end()) return true;
         st.insert(x);
    }
    
     for(auto x:arr)
     {
        if(x!=0 && st.find(2*x)!=st.end()) return true;
     }
     return false;
    
    }
};