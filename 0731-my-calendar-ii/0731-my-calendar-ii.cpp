class MyCalendarTwo {
public:
    //Sweep Line algorithm
    map<int, int> eventCnt;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        eventCnt[start]++;
        eventCnt[end]--;

        int changes = 0;
        for(auto it: eventCnt){
            changes += it.second;

            if(changes >= 3){
                eventCnt[start]--;
                eventCnt[end]++;
                return false;
            }
        }

        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */