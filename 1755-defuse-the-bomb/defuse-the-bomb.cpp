class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>temp=code;
        int n=code.size();
        if(k==0)
        {
            
            for(int i=0;i<n;i++) temp[i]=0;
        }
        if(k>0)
        {
            int m=k;
            for(int i=0;i<n;i++)
            { 
                m=k;
                int val=0;
                int j=0;
                while(j<m)
                {
                   val+=code[(i+j+1)%n];
                   j++;
                }
                temp[i]=val;
            }
        }
        if(k<0)
        {
            int m;
            for(int i=0;i<n;i++)
            { 
                m=abs(k);
                int val=0;
                int j=0;
                while(j<m)
                {
                   val+=code[abs(i-j+n-1)%n];
                   j++;
                }
                temp[i]=val;
            }
        
        }
        return temp;
    }
};