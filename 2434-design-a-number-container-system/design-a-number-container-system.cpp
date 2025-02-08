class NumberContainers {
public:
  unordered_map<int,int>mp;
  unordered_map<int,set<int>>mp1;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
          if(mp.find(index)!=mp.end())
          {
              int val=mp[index];
              if(mp1[val].find(index)!=mp1[val].end())
              {
                mp1[val].erase(index);
              }
          }
          mp[index]=number;
          mp1[number].insert(index);
    }
    
    int find(int number) {
        
        if(mp1[number].size()) return *mp1[number].begin();
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */