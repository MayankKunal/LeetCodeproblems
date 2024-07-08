class Solution {
    int help(int index,vector<int>&arr,int k)
    {
        if(arr.size()==1)
        {
            return arr[0];
        }
         index=(index+k)%arr.size();
        arr.erase(arr.begin()+index);
       return help(index,arr,k);
    }
public:
    int findTheWinner(int n, int k) {
        vector<int>arr(n);
        k=k-1;
        for(int i=0;i<n;i++)
        {
            arr[i]=i+1;
        }
        return help(0,arr,k);
    }
};