class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        
        int n=bills.size();
        int five=0,ten=0,twety=0;
        for(int i=0;i<n;i++)
        {
            if(bills[i]==5) five++;
            else if(bills[i]==10)
            {
                ten++;
                if(five) five--;
                else return false;
            }
            else
            {
                if(five>=3 || ten>=1&& five>=1) 
                {
                    if(ten>=1 && five>=1)
                    {
                        ten--;
                        five--;
                    }
                    else
                    {
                        five-=3;
                    }
                }
                else return false;
            }
        }
        return true;
    }
};