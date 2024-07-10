class Solution {
public:
    int minOperations(vector<string>& logs) {
        string back="../";
        string rest="./";
        int count=0;
        for(string log:logs)
        {
          if(log==back)
          {
            if(count) count--;
          }
             else if (log==rest) continue;
             else count++;
        }
        return count;
    }
};