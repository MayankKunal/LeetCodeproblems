class Solution {
    static bool comparator(string &a,string &b)
    {
        return a+b>b+a;
    }
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string>temp;
        // if(nums[0] == 0) return "0";
        for(auto x:nums)
        {
            string des=to_string(x);
            temp.push_back(des);
        }
        sort(temp.begin(),temp.end(),comparator);
         if(temp[0]=="0") return "0";
        string ans="";
        for(auto x:temp)
        {
            ans+=x;
        }
        return ans;

    }
};