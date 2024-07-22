class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        int n=names.size();
        vector<pair<int,string>>arr;
        for(int i=0;i<n;i++)
        {
            arr.push_back({heights[i],names[i]});
        }
 sort(arr.rbegin(),arr.rend());
 
        vector<string>ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(arr[i].second);
        }
        return ans;
    }
};