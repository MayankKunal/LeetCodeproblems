class Solution {
public:
    int countSeniors(vector<string>& details) {
        
        
        int count=0;
        for(string detail:details)
        {
            string str=detail.substr(11,2);
            cout<<str<<endl;
            int age=stoi(str);
            if(age>60) count++;
        }
        return count;
    }
};