class MyCalendar {
public:
    MyCalendar() {
        
        
    }
    vector<pair<int,int>>booking;
    bool book(int start, int end) {
        
        if(booking.size()==0) 
        {
            booking.push_back({start,end});
            return true;
        }
        else
        {
           for(auto x:booking)
           {
            int s=x.first,e=x.second;
            if(!(start<=s && end<=s || start>=e && end>=e))
            {
                return false;
            }
           }
           booking.push_back({start,end});
           return true;
        }
return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */