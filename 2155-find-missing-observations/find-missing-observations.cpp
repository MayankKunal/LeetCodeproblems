class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int m=rolls.size();
        int total=(mean)*(m+n);
        int dice1=0;
        for(int x:rolls)
        {
            dice1+=x;
        }
        cout<<dice1<<"\n";
        int left=total-dice1;
        cout<<total<<" "<<left<<"\n";
        int mod=left%n;
        int ele=left/n;
        cout<<ele<<" "<<mod;
        vector<int>arr;
        if(ele>6 || ele<=0) return arr;
        
        for(int i=0;i<n;i++)
        {
            arr.push_back(ele);
        }
        for(int i=0;i<mod;i++)
        {
            arr[i]+=1;
            if(arr[i]>6) return {};
        }
        return arr;
    }
};