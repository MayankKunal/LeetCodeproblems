class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int n=A.size();
        vector<int>ans(n);
          vector<int>freq(n+1,0);
          int val=0;
          for(int i=0;i<n;i++)
          {
                  freq[A[i]]++;
                  freq[B[i]]++;
                  if(A[i]!=B[i] && freq[A[i]]==2 && freq[B[i]]==2) val+=2;
                  else if(freq[B[i]]==2 || freq[A[i]]==2) val+=1;
                  ans[i]=val;
          }
          return ans;
    }
};