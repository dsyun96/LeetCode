class MyCalendar {
public:
    vector<pair<int, int>> vec;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto [a, b] : vec) {
            if (end <= a || b <= start) continue;
            return false;
        }
        vec.emplace_back(start, end);
        return true;
    }
        
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */