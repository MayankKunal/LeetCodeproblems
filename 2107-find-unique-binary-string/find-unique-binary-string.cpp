class Solution {
void help(int o,int z,int n,string temp,unordered_set<string>&st)
{
    
        if(temp.size()==n)
        {
        st.insert(temp);
        return;
         }
    if(o<n)
    {
        help(o+1,z,n,temp+'1',st);
    }
    if(z<n)
    help(o,z+1,n,temp+'0',st);
}
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        int n=nums.size();
        unordered_set<string>st;
        help(0,0,n,"",st);
        for(auto num:nums)
        {
            st.erase(num);
        }
        
        
        if(st.size())
        return *st.begin();
          
          return "-1";
    }
};