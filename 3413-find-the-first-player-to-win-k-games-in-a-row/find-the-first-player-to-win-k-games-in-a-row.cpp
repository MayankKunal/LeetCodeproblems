class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        
        deque<int>q;
        for(int x:skills)
        {
            q.push_back(x);
        }
        int n=skills.size();
        if(k>n)
        {
            k=n;
        }
        int count=0;
        while(true)
        {
            
           int first=q.front();
           q.pop_front();
           int second=q.front();
           q.pop_front();
           
           if(count==0)
           {
              if(first>second)
              {
                q.push_back(second);
                q.push_front(first);
              }
              else
              {
                 q.push_back(first);
                q.push_front(second);
              }
              count++;
           }
           else
           {
             if(first>second)
              {
                q.push_back(second);
                q.push_front(first);
                count++;
              }
              else
              {
                 q.push_back(first);
                q.push_front(second);
                count=1;
              }
           }

           if(count==k)
           {
            break;
           }
           
        }
int ele=q.front();
for(int i=0;i<n;i++)
{
    if(skills[i]==ele) return i;
}
return -1;
    }
};