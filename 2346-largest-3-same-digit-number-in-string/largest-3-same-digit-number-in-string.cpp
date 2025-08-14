class Solution {
public:
    string largestGoodInteger(string num) {
        
        int n=num.size();
        string ans="";
        for(int i=0;i<n-2;i++)
        {
            if(num[i]==num[i+1] && num[i]==num[i+2])
            {
                string temp=num.substr(i,3);
                cout<<temp;
                ans=max(ans,temp);
            }
        }
        return ans;
    }
};