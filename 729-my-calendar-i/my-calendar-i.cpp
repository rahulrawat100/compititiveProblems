class MyCalendar {
public:
    map<int, int> D;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        if(D.size()==0)
        {
            D[start]=end;
            return true;
        }
        auto it = D.lower_bound(start);
        if(it!=D.end() && it->first<end)
           return false;
        if(it==D.begin())
        {
            D[start]=end;
             return true;  
        }   
        it--;
        if(it->second>start)
          return false;
       D[start]=end;
       return true;       
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */