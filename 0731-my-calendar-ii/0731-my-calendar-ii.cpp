class MyCalendarTwo {
public:
    set<pair<int, int>> doubleBooking;  //store where double booking happened : overlapping interval
    set<pair<int, int>> singleBooking;  //unique non-overlapping intervals

    bool checkOverlap(int start1, int end1, int start2, int end2){
        return max(start1, start2) < min(end1, end2);
    }

    pair<int, int> overlappedRegion(int start1, int end1, int start2, int end2){
        return {max(start1, start2), min(end1, end2)};
    }

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        //check if it overlaps with doubleBooked interval
        for(auto p: doubleBooking){
            if(checkOverlap(p.first, p.second, start, end)) return false;
        }

        for(auto p: singleBooking){
            if(checkOverlap(p.first, p.second, start, end)){
                doubleBooking.insert(overlappedRegion(p.first, p.second, start, end));
            }
        }

        singleBooking.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */