class Solution {
public:
    int maximumSwap(int num) {
        
        string s=to_string(num);
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            char curr=s[i];
            int index=-1;
            for(int j=i+1;j<n;j++)
            {
                if(s[j]>=curr)
                {
                      curr=s[j];
                      index=j;
                }
            }
            if(curr!=s[i])
            {
                swap(s[i],s[index]);
                break;
            }
        }
        return stoi(s);
    }
};